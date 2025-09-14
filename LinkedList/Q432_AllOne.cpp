#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;


class AllOne {
private:
    struct Node {
        int count;
        string str;
        Node* pre;
        Node* next;
        Node(string s): count(0),str(s),pre(nullptr),next(nullptr) {}
        Node(string s, Node* prev): count(1),str(s),pre(prev),next(prev->next) {
            prev->next->pre=this;
            prev->next=this;
        }
        void print() {
            Node* cur=this;
            while (cur!=nullptr) {
                cout<<"("<<cur->str<<"*"<<cur->count<<"),";
                cur=cur->next;
            }
            cout<<endl;
        }
    };

    Node *head,*tail;
    unordered_map<string,Node*> mp;


public:
    AllOne() {
        head=new Node("head");
        tail=new Node("tail");
        head->next=tail;
        tail->pre=head;
    }
    
    void inc(string key) {
        if (!mp.count(key)) {
            Node* n=new Node(key,head);
            mp[key]=n;
        } else {
            Node* n=mp[key];
            n->count++;
            while (n->next!=tail && n->count>n->next->count) {
                Node *pre=n->pre,*next=n->next,*nextnext=n->next->next;
                n->pre=next;
                n->next=nextnext;
                next->pre=pre;
                next->next=n;
                pre->next=next;
                nextnext->pre=n;
            }
        }
        // head->print();
    }
    
    void dec(string key) {
        if (!mp.count(key)) return;
        Node* n=mp[key];
        n->count--;
        if (n->count==0) {
            n->pre->next=n->next;
            n->next->pre=n->pre;
            mp.erase(key);
            delete n;
        }
        else while (n->pre!=head && n->count<n->pre->count) {
            Node *pre=n->pre,*next=n->next,*prepre=n->pre->pre;
            n->pre=prepre;
            n->next=pre;
            pre->pre=n;
            pre->next=next;
            prepre->next=n;
            next->pre=pre;
        }
        // head->print();
    }
    
    string getMaxKey() {
        if (head->next==tail) return "";
        // head->print();
        // cout<<"max:"<<tail->pre->str<<endl;
        return tail->pre->str;
    }
    
    string getMinKey() {
        if (head->next==tail) return "";
        // head->print();
        // cout<<"min:"<<head->next->str<<endl;
        return head->next->str;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

int main() {
    return 0;
}