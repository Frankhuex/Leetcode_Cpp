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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA==NULL || headB==NULL) return NULL;
        ListNode *i=headA,*j=headB;
        while (true) {
            if (i==j) return i;
            if (i==NULL) i=headB;
            else i=i->next;
            if (j==NULL) j=headA;
            else j=j->next;
        }
    }
};
int main() {
    return 0;
}