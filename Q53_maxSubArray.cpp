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
    int maxSubArray(vector<int>& nums) {
        int pre=0;
        int ans=nums[0];
        for (const int &n:nums) {
            pre=max(pre+n,n);
            ans=max(pre,ans);
        }
        return ans;
    }
};
int main() {
    return 0;
}