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
    int jump(vector<int>& nums) {
        int lastFurthest=-1, thisFurthest=0, nextFurthest=0, jumps=0;
        while (thisFurthest<nums.size()-1) {
            nextFurthest=thisFurthest;
            for (int i=lastFurthest+1; i<=thisFurthest; ++i) {
                nextFurthest=max(nextFurthest, i+nums[i]);
            }
            ++jumps;
            lastFurthest=thisFurthest;
            thisFurthest=nextFurthest;
        }
        return jumps;
    }
};

int main() {
    return 0;
}