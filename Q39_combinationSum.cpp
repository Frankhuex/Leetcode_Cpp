#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        sort(candidates.begin(),candidates.end(),greater<int>());
        dfs(ans,tmp,candidates,0,target);
        return ans;
    }

    void dfs(vector<vector<int>>& ans, vector<int>& tmp, vector<int>& candidates, int lastIndex, int target) {
        if (target==0) {
            ans.push_back(tmp);
            return;
        }
        for (int i=lastIndex;i<candidates.size();++i) {
            if (candidates[i]<=target) {
                tmp.push_back(candidates[i]);
                dfs(ans,tmp,candidates,i,target-candidates[i]);
                tmp.pop_back();
            } 
        }

    }
};

int main() {
    return 0;
}