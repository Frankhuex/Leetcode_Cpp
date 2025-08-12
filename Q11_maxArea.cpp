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
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int hi,hj;
        int area;
        int max_area=0;
        while (i<j) {
            hi=height[i];
            hj=height[j];
            area=min(hi,hj)*(j-i);
            max_area=max(area,max_area);
            hi>hj?--j:++i;
        }
        return max_area;
    }
};
int main() {
    return 0;
}