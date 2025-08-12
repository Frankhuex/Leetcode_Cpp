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

struct DoubleLLNode {
    int key,value;
    DoubleLLNode* pre;
    DoubleLLNode* next;
    DoubleLLNode(): key(0), value(0), pre(nullptr), next(nullptr) {}
    DoubleLLNode(int _key, int _value): key(_key), value(_value), pre(nullptr), next(nullptr) {}
};

class DoubleLL {
public:
    DoubleLLNode* head;
    DoubleLLNode* tail;
    int used;
    DoubleLL() {
        used=0;
        head=new DoubleLLNode();
        tail=new DoubleLLNode();
        head->next=tail;
        tail->pre=head;
    }
    DoubleLLNode* removeNode(DoubleLLNode* target) {        
        DoubleLLNode* pre=target->pre;
        DoubleLLNode* next=target->next;
        pre->next=next;
        next->pre=pre;      
        --used;
        return target;
    }
    DoubleLLNode* addFirst(DoubleLLNode* target) {
        DoubleLLNode* first=head->next;
        head->next=target;
        first->pre=target;
        target->pre=head;
        target->next=first;
        ++used;
        return target;
    }
    DoubleLLNode* moveToFirst(DoubleLLNode* target) {
        removeNode(target);
        addFirst(target);
        return target;
    }
};

class LRUCache {
private:
    int capacity;
    DoubleLL list;
    unordered_map<int,DoubleLLNode*> cache;
    
    void printVector(vector<int> &v) {
        for (int i=0;i<v.size();++i) {
            cout<<v[i]<<",";
        }
        cout<<endl;
    }
    void printMap(unordered_map<int,int> &m) {
        for (const auto& pair:m) {
            cout<<pair.first<<": "<<pair.second<<endl;
        }
    }
public:
    LRUCache(int _capacity) {
        capacity=_capacity;
        list=DoubleLL();
    }
    
    int get(int key) {
        if (cache.count(key)) {
            DoubleLLNode* target=cache[key];
            list.moveToFirst(target);
            return target->value;
        }              
        return -1;
        
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            DoubleLLNode* target=cache[key];
            target->value=value;
            list.moveToFirst(target);
        }
        else if (list.used<capacity) {
            DoubleLLNode* target=new DoubleLLNode(key,value);
            list.addFirst(target);
            cache[key]=target;
        }
        else {          
            cache.erase(list.tail->pre->key);
            list.removeNode(list.tail->pre);
            put(key,value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


class LRUCacheOld {
private:
    int capacity;
    int used;
    vector<int> index2key; 
    unordered_map<int,int> key2index; 
    unordered_map<int,int> key2value;
    void printVector(vector<int> &v) {
        for (int i=0;i<v.size();++i) {
            cout<<v[i]<<",";
        }
        cout<<endl;
    }
    void printMap(unordered_map<int,int> &m) {
        for (const auto& pair:m) {
            cout<<pair.first<<": "<<pair.second<<endl;
        }
    }
    void printAll() {
        cout<<"index2key:"<<endl;
        printVector(index2key);
        cout<<"key2index:"<<endl;
        printMap(key2index);
        cout<<"key2value:"<<endl;
        printMap(key2value);
        cout<<endl;
    }
public:
    LRUCacheOld(int capacity) {
        this->capacity=capacity;
        used=0;
    }
    
    int get(int key) {
        if (key2value.count(key)) {
            int targetIndex=key2index[key];
            for (int i=targetIndex;i<used-1;++i) {
                index2key[i]=index2key[i+1];
                key2index[index2key[i]]--;
            }
            index2key[used-1]=key;
            key2index[key]=used-1;
            printAll();
            return key2value[key];
        }
        
        else {
            printAll();
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (key2value.count(key)) {
            key2value[key]=value;
            get(key);
        }
        else if (used<capacity) {
            ++used;
            index2key.push_back(key);
            key2index[key]=used-1;
            key2value[key]=value;
        }
        else {          
            key2index.erase(index2key[0]);
            key2value.erase(index2key[0]);
            index2key.erase(index2key.begin());
            --used;
            for (int i=0;i<used;++i) {
                key2index[index2key[i]]--;
            }
            put(key,value);
        }
        printAll();
    }
};

int main() {
    return 0;
}