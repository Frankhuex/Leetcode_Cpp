#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
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
    ListNode* reverseList(ListNode* head) {
        if (head==NULL || head->next==NULL) return head;
        ListNode *ans=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return ans;
    }
    ListNode* reverseList2(ListNode* head) {
        ListNode *pre=nullptr;
        ListNode *cur=head;
        ListNode *next;
        while (cur) {
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
};
int main() {
    return 0;
}