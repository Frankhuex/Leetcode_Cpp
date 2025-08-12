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
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows,cols;
        int row=matrix.size(),col=matrix[0].size();
        for (int r=0;r<row;++r) {
            for (int c=0;c<col;++c) {
                if (!matrix[r][c]) {
                    if (rows.empty() || !rows.count(r)) {
                        rows.insert(r);
                    }
                    if (cols.empty() || !cols.count(c)) {
                        cols.insert(c);
                    }
                }
            }
        }
        for (int r:rows) {
            for (int c=0;c<col;++c) {
                matrix[r][c]=0;
            }
        }
        for (int c:cols) {
            for (int r=0;r<row;++r) {
                matrix[r][c]=0;
            }
        }
    }
};
int main() {
    return 0;
}