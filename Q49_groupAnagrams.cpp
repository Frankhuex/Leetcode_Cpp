#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        vector<vector<string>> ans;
        int i=-1;
        for (string str:strs) {
            string key=str;
            sort(key.begin(),key.end());
            map[key].emplace_back(str);
        }
        for (auto it=map.begin();it!=map.end();++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};
int main() {
    return 0;
}