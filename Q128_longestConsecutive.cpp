#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int& num:nums) {
            num_set.insert(num);
        }
        int longestStreak=0;
        int currentStreak;
        int currentNum;
        for (const int& num:num_set) {
            if (!num_set.count(num-1)) {
                currentStreak=1;
                currentNum=num;
                while (num_set.count(currentNum+1)) {
                    ++currentNum;
                    ++currentStreak;
                }
                longestStreak=max(longestStreak,currentStreak);
            }
        }
        return longestStreak;
    }
};
int main() {
    return 0;
}