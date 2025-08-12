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
    int firstMissingPositive(vector<int>& nums) {
        int size=nums.size();
        int ans=1;
        for (int i=0;i<size;++i) {
            if (nums[i]<=0) nums[i]=size+1;
        }
        for (int i=0;i<size;++i) {
            int n=abs(nums[i]);
            if (n<=size)
                nums[n-1]=-abs(nums[n-1]);
        }
        for (int i=0;i<size;++i) {
            if (nums[i]>0) return i+1;
        }
        return size+1;
    }
};
int main() {
    return 0;
}