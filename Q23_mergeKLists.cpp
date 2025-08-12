#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <math.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=NULL;
        ListNode* tail;
        int min,min_i;
        bool empty;
        while (true) {
            min=pow(10,4);
            min_i=0;
            empty=true;
            for (int i=0;i<lists.size();i++) {
                if (lists[i]==NULL) continue;
                if (lists[i]->val<min) {
                    empty=false;
                    min=lists[i]->val;
                    min_i=i;
                }
            }
            if (empty) break;
            if (head==NULL) {
                head=new ListNode(min);
                tail=head;
            }
            else {
                tail->next=new ListNode(min);
                tail=tail->next;
            }
            lists[min_i]=lists[min_i]->next;
        }
        return head;
    }
};
int main() {
    return 0;
}