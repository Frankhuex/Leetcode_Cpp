#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        return findTarget(nums,0,nums.size()-1);
    }

    int findTarget(vector<int>& nums, int left, int right) {
        if (left>right) return -1;
        if (left==right) return nums[left];
        int mid=(left+right)/2;
        if (nums[left]<=nums[mid]) {
            if (nums[mid+1]<=nums[right] && nums[mid+1]>nums[mid]) {
                return findTarget(nums,left,mid);
            }
            return findTarget(nums,mid+1,right);
        }
        return findTarget(nums,left,mid);

    }
};

int main() {
    return 0;
}