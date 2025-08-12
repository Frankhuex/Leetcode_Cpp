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
    int search(vector<int>& nums, int target) {
        return searchTarget(nums,target,0,nums.size()-1);
    }
    int searchTarget(vector<int>& nums, int target, int left, int right) {
        if (left>right) return -1;
        if (left==right) {
            return nums[left]==target?left:-1;
        }
        int mid=(left+right)/2;
        if (nums[left]<nums[mid]) {
            if (nums[left]<=target && target<=nums[mid]) {
                return searchTarget(nums,target,left,mid);
            }
            return searchTarget(nums,target,mid+1,right);
        } else {
            if (nums[mid+1]<=target && target<=nums[right]) {
                return searchTarget(nums,target,mid+1,right);
            }
            return searchTarget(nums,target,left,mid);
            
        }

        
    }
};

int main() {
    return 0;
}