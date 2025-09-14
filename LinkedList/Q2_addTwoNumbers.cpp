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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=new ListNode();
        ListNode *cur=head;
        int c=0;
        while (l1 || l2) {
            int n1=(l1?l1->val:0);
            int n2=(l2?l2->val:0);
            int s=n1+n2+c;
            cur->next=new ListNode(s%10);
            c=(s>=10);
            cur=cur->next;
            if (l1) l1=l1->next;
            if (l2) l2=l2->next;
        }
        if (c) cur->next=new ListNode(1);
        return head->next;
    }
};

int main() {
    return 0;
}