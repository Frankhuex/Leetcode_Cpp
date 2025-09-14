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
        if (head==nullptr || head->next==nullptr) return head;
        ListNode *ans=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return ans;
    }
    ListNode* reverseList2(ListNode* head) {
        ListNode *cur=head, *pre=nullptr;
        while (cur) {
            ListNode *next=cur->next;
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