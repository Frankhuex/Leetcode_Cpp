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


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dum=new ListNode(0,head);
        ListNode *preLeft=dum;
        for (int i=1;i<left;i++) {
            preLeft=preLeft->next;
        }
        ListNode *cur=preLeft->next;
        ListNode *leftNode=cur;
        ListNode *pre=cur;
        cur=cur->next;
        for (int i=left+1;i<=right;i++) { // Node [left+1,right] need to change pointer to pre
            ListNode *next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        preLeft->next=pre;
        leftNode->next=cur;
        return dum->next;
    }
};

int main() {
    return 0;
}