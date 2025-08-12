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
    bool isPalindrome(ListNode* head) {
        vector<int> array;
        while (head!=nullptr) {
            array.push_back(head->val);
            head=head->next;
        }
        int size=array.size();
        for (int i=0;i<(size+1)/2;++i) {
            if (array[i]!=array[size-1-i]) return false;
        }
        return true;
    }
};
int main() {
    return 0;
}