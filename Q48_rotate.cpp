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
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for (int i=0;i<(n+1)/2;++i) {
            for (int j=0;j<n/2;++j) {
                int i2=j,i3=n-1-i,i4=n-1-j;
                int j2=n-1-i,j3=n-1-j,j4=i;
                int mij=matrix[i][j];
                matrix[i][j]=matrix[i4][j4];
                matrix[i4][j4]=matrix[i3][j3];
                matrix[i3][j3]=matrix[i2][j2];
                matrix[i2][j2]=mij;
            }
        }
    }
};
int main() {
    return 0;
}