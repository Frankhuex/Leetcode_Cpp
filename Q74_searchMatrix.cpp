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
    int cnum;
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rnum=matrix.size();
        cnum=matrix[0].size();
        int endIndex=rnum*cnum-1;
        return search(matrix,target,0,endIndex);
    }

    pair<int,int> index2rc(int index, int cnum) {
        return make_pair(index/cnum,index%cnum);
    }

    bool search(vector<vector<int>>& matrix, int target, int left, int right) {
        pair<int,int> leftRC=index2rc(left,cnum);
        pair<int,int> rightRC=index2rc(right,cnum);
        int leftR=leftRC.first,leftC=leftRC.second;
        int rightR=rightRC.first,rightC=rightRC.second;
        if (left==right) {
            return matrix[leftR][leftC]==target;
        } 
        int mid=(left+right)/2;
        pair<int,int> midRC=index2rc(mid,cnum);
        int midR=midRC.first,midC=midRC.second;
        if (matrix[midR][midC]>=target) return search(matrix,target,left,mid);
        return search(matrix,target,mid+1,right);
    }

};
int main() {
    return 0;
}