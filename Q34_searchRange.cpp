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
    vector<int> ans;
    vector<int> searchRange(vector<int>& nums, int target) {
        ans.assign(2,-1);
        search(nums,target,0,nums.size()-1);
        return ans;
    }

    void search(vector<int>& nums, int target, int left, int right) {
        if (left>right) return;
        if (left==right) {
            if (nums[left]==target) {
                ans[0]=(ans[0]==-1)?left:min(ans[0],left);
                ans[1]=max(ans[1],right);
            }
        } else {
            int mid=(left+right)/2;
            if (nums[mid]>=target) {
                search(nums,target,left,mid);
            }
            if (nums[mid]<=target) {
                search(nums,target,mid+1,right);
            }
        }
    }

};
int main() {
    return 0;
}