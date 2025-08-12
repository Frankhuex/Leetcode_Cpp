#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;
//因数个数
class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int count;
        int max_count=-1;
        int min_d=0;
        sort(nums.begin(),nums.end());
        for (int d:divisors) {
            count=0;
            for (int n:nums) {
                if (n<d) break;
                if (n%d==0) ++count;
            }
            if (count>max_count || (count==max_count && d<min_d)) {
                max_count=count;
                min_d=d;
            }
        }
        return min_d;
    }
};
int main() {
    return 0;
}