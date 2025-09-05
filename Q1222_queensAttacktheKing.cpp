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
#include <unordered_set>

using namespace std;
int main() {
    return 0;
}
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        unordered_set<int> qset;
        vector<vector<int>> ans;
        for (auto& q: queens) {
            qset.insert(q[0]*8+q[1]);
        }
        int x,y;
        int dirs[3]={-1,0,1};
        for (int i: dirs) {
            for (int j: dirs) {
                if (!i && !j) continue;
                x=king[0];
                y=king[1];
                while (x>=0 && x<8 && y>=0 && y<8) {
                    x+=i;
                    y+=j;
                    if (x<0 || x>=8 || y<0 || y>=8) break;
                    if (qset.count(x*8+y)) {
                        ans.push_back(vector<int>{x,y});
                        break;
                    }
                }
            }
        }

        return ans;
    }


};