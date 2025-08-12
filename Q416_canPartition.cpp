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
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (int n: nums) sum+=n;
        if (sum%2==1) return false;
        int size=nums.size();
        vector<vector<bool>> dp(size+1,vector<bool>(sum/2+1,false));
        for (int i=0;i<=size;++i) {
            dp[i][0]=true;
        }
        
        for (int i=1;i<=size;++i) {
            for (int j=1;j<=sum/2;++j) {
                if (j>=nums[i-1]) {
                    dp[i][j]=dp[i-1][j-nums[i-1]];
                }
                dp[i][j]=dp[i][j]||dp[i-1][j];
            }
        }
        return dp[size][sum/2];
    }
};

int main() {
    return 0;
}