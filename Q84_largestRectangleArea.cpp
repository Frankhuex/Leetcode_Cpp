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
    int largestRectangleArea(vector<int>& heights) {
        int size=heights.size();
        vector<int> stack1,stack2;
        vector<int> closestShorterLeft(size,-1);
        vector<int> closestShorterRight(size,size);
        for (int i=0;i<size;++i) {
            while (!stack1.empty() && heights[stack1.back()]>=heights[i]) {
                stack1.pop_back();
            }
            closestShorterLeft[i]=stack1.empty()?-1:stack1.back();
            stack1.push_back(i);
            

            int j=size-1-i;
            while (!stack2.empty() && heights[stack2.back()]>=heights[j]) {
                stack2.pop_back();
            }
            closestShorterRight[j]=stack2.empty()?size:stack2.back();
            stack2.push_back(j);
        }
        int maxArea=0;
        for (int i=0;i<size;++i) {
            // cout<<closestShorterLeft[i]<<","<<closestShorterRight[i]<<endl;
            maxArea=max(maxArea,(closestShorterRight[i]-closestShorterLeft[i]-1)*heights[i]);
        }
        return maxArea;
    }
};
int main() {
    return 0;
}