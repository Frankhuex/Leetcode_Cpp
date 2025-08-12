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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size=temperatures.size();
        vector<int> stack;
        vector<int> ans(size,0);
        for (int i=0;i<size;++i) {
            while (!stack.empty() && temperatures[stack.back()]<temperatures[i]) {
                ans[stack.back()]=i-stack.back();
                stack.pop_back();
            }
            stack.push_back(i);
        }
        return ans;
    }
};

int main() {
    return 0;
}