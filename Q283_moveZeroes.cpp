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
    void moveZeroes(vector<int>& nums) {
        int n0=0;
        for (int i=0;i<nums.size();++i) {
            if (nums[i]==0) ++n0;
            else if (n0!=0) {
                nums[i-n0]=nums[i];
                nums[i]=0;
            }
        }
    }
};
int main() {
    return 0;
}