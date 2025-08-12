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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size(),col=matrix[0].size();
        int r=0,c=0;
        int left=-1,up=-1,right=col,down=row;
        vector<int> ans;
        while (left<right && up<down) {
            if (c>=right) break;
            while (c<right) {
                ans.push_back(matrix[r][c++]);
            }
            --c;++r;++up;
            if (r>=down) break;
            while (r<down) {
                ans.push_back(matrix[r++][c]);
            }
            --r;--c;--right;
            if (c<=left) break;
            while (c>left) {
                ans.push_back(matrix[r][c--]);
            }
            ++c;--r;--down;
            if (r<=up) break;
            while (r>up) {
                ans.push_back(matrix[r--][c]);
            }
            ++r;++c;++left;
        }
        return ans;
    }
};
int main() {
    return 0;
}