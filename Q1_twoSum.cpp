#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
//两数之和
class Solution {
public:
    void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    int partition(vector<int> &nums, int left, int right,vector<int> &indices) {
        // 以 nums[left] 为基准数
        int i = left, j = right;
        while (i < j) {
            while (i < j && nums[j] >= nums[left])
                j--; // 从右向左找首个小于基准数的元素
            while (i < j && nums[i] <= nums[left])
                i++;          // 从左向右找首个大于基准数的元素
            swap(nums, i, j); // 交换这两个元素
            swap(indices,i,j);
        }
        swap(nums, i, left); // 将基准数交换至两子数组的分界线
        swap(indices,i,left);
        return i;            // 返回基准数的索引
    }

    void quickSort(vector<int> &nums, int left, int right, vector<int> &indices) {
        // 子数组长度为 1 时终止递归
        if (left >= right)
            return;
        // 哨兵划分
        int pivot = partition(nums, left, right,indices);
        // 递归左子数组、右子数组
        quickSort(nums, left, pivot - 1,indices);
        quickSort(nums, pivot + 1, right,indices);
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        int sum;
        vector<int> result(2,-1);
        vector<int> indices(nums.size());
        for (int i=0;i<indices.size();++i) {
            indices[i]=i;
        }
        quickSort(nums,i,j,indices);
        while (i<j) {
            sum=nums[i]+nums[j];
            if (sum<target) ++i;
            else if (sum>target) --j;
            else {
                result[0]=indices[i];
                result[1]=indices[j];
                return result;
            }
        }
        return result;
    }  

    // Better solution using hash table
    vector<int> twoSum2(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        vector<int> result(2,-1);
        int n;
        for (int i=0;i<nums.size();++i) {
            n=nums[i];
            if (hash.count(target-n)) {
                result[0]=i;
                result[1]=hash[target-n];
                return result;
            }
            hash[n]=i;
        }
        return result;
    }
};

int main() {
    return 0;
}