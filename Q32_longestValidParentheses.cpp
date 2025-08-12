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
    int longestValidParentheses(string s) {
        if (s.size()<2) return 0;
        vector<int> dp(s.size(),0);
        int ans=0;
        if (s[0]=='(' && s[1]==')') {
            dp[1]=2;
            ans=2;
        }
        for (int i=2;i<s.size();++i) {
            if (s[i]==')') {
                if (s[i-1]=='(')
                    dp[i]=dp[i-2]+2;
                else { //s[i-1]==')'
                    //j2,dp[j1-1]brkts,j1,dp[i-2]brkts,i-1,i
                    int j1=i-2-dp[i-2];
                    if (j1>=0) {
                        if (s[j1]=='(' && j1>=1) {
                            int j2=j1-1-dp[j1-1];
                            if (j2>=0) {
                                if (s[j2]=='(') {
                                    if (j2>=1)
                                        dp[i]=dp[i-2]+dp[j1-1]+dp[j2-1]+4;
                                    else 
                                        dp[i]=dp[i-2]+dp[j1-1]+4;
                                }
                            }
                        }
                    }
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
int main() {
    return 0;
}