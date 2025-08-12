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
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size=nums.size();
        int target,sum;
        int i,j,k;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for (i=0;i<size-2;++i) {
            if (i>0 && nums[i]==nums[i-1]) continue;
            j=i+1; 
            k=size-1;
            while (j<k) {
                sum=nums[i]+nums[j]+nums[k];
                if (sum==0) {
                    ans.push_back({nums[i],nums[j++],nums[k--]});
                    while (j<k && nums[j]==nums[j-1]) ++j;
                    while (j<k && nums[k]==nums[k+1]) --k;
                }
                else if (sum<0) ++j;
                else --k;
            }
        }
        return ans;
    }
};
int main() {
    return 0;
}