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
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> nums_copy;
        for (int n:nums) nums_copy.push_back(n);
        int size=nums.size();
        for (int i=0;i<size;++i) {
            nums[(i+k)%size]=nums_copy[i];
        }
    }
};
int main() {
    return 0;
}