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
    int maxProduct(vector<int>& nums) {
        long minL=(long)nums[0], maxL=(long)nums[0], ans=(long)nums[0];
        for (int i=1;i<nums.size();++i) {
            long minL1=minL,maxL1=maxL;
            minL=min(minL1*nums[i],min(maxL1*nums[i],(long)nums[i]));
            maxL=max(minL1*nums[i],max(maxL1*nums[i],(long)nums[i]));
            ans=max(maxL,ans);
        }
        return ans;
    }
};

int main() {
    return 0;
}