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
    vector<int> productExceptSelf(vector<int>& nums) {
        int size=nums.size();
        vector<int> ans(size,0);
        vector<int> left(size,0);
        int right=1;
        left[0]=1;
        for (int i=1;i<size;++i) {
            left[i]=left[i-1]*nums[i-1];
        }
        for (int i=size-1;i>=0;--i) {
            ans[i]=left[i]*right;
            right=right*nums[i];
        }
        return ans;
    }
};
int main() {
    return 0;
}