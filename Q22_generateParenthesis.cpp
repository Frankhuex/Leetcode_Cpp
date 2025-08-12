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
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n==0) {
            return vector<string>(1,"");
        }
        for (int i=0;i<=n-1;++i) {
            vector<string> inside=generateParenthesis(i);
            vector<string> outside=generateParenthesis(n-1-i);
            for (string ins: inside) {
                for (string out: outside) {
                    ans.push_back("("+ins+")"+out);
                }
            }
        }
        return ans;
    }
};