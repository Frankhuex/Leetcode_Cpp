#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        for (string w: wordDict) {
            wordSet.insert(w);
        }
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        for (int i=1;i<=s.size();++i) {
            for (int j=0;j<i;++j) {
                if (dp[j]) {
                    string sub=s.substr(j,i-j);
                    cout<<sub<<endl;
                    if (wordSet.count(sub)) {
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};

int main() {
    return 0;
}