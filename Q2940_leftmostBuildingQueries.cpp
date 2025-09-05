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
int main() {
    return 0;
}

class Solution {
public:
    vector<int> segtree;
    void build(int l, int r, int rt, vector<int>& heights) {
        if (l==r) {
            segtree[rt]=heights[l];
            return;
        }
        int m=(l+r)/2;
        build(l,m,rt*2+1,heights);
        build(m+1,r,rt*2+2,heights);
        segtree[rt]=max(segtree[rt*2+1],segtree[rt*2+2]);
    }

    int query(vector<int>& heights, vector<int>& query) {
        int a=query[0],b=query[1];
        int l=(a<b?a:b),r=(a>b?a:b);
        if (l==r || heights[l]<heights[r]) return r;
        
    }


    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {

    }
};