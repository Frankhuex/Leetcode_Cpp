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
    vector<vector<bool>> isPalindrome;

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n=s.size();
        isPalindrome.assign(n,vector<bool>(n,true));
        for (int i=n-1;i>=0;--i) {
            for (int j=i+1;j<n;++j) {
                isPalindrome[i][j]=(s[i]==s[j])&&(isPalindrome[i+1][j-1]);
            }
        }
        dfs(s,0,vector<string>(),ans);
        return ans;
    }

    void dfs(string& s, int left, vector<string> tmp, vector<vector<string>>& ans) {
        if (left==s.size()) {
            ans.push_back(tmp);
            return;
        }
        for (int i=left;i<s.size();++i) {
            if (isPalindrome[left][i]) {
                tmp.push_back(s.substr(left,i-left+1));
                dfs(s,i+1,tmp,ans);
                tmp.pop_back();
            }
        }
    }

};
int main() {
    return 0;
}