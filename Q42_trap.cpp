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
    int trap(vector<int>& height) {
        stack<int> stk;
        int ans=0;
        for (int i=0;i<height.size();++i) {
            while (!stk.empty() && height[i]>height[stk.top()]) {
                int bottom=stk.top();
                stk.pop();
                if (stk.empty()) break;
                int left=stk.top();
                ans+=(min(height[left],height[i])-height[bottom])*(i-left-1);
            }
            stk.push(i);
        }
        return ans;
    }

    int trap2(vector<int>& height) {
        int ans=0;
        int left=0,right=height.size()-1;
        int leftMax=0, rightMax=0;
        while (left<right) {
            int hl=height[left],hr=height[right];
            leftMax=max(leftMax,hl);
            rightMax=max(rightMax,hr);
            if (hl<hr) {
                ans+=min(leftMax,rightMax)-hl;
                ++left;
            }
            else {
                ans+=min(leftMax,rightMax)-hr;
                --right;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}