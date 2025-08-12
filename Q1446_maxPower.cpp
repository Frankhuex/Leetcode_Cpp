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
    int maxPower(string s) {
        int max_power=0;
        int power=1;
        for (int i=1;i<s.size();++i) {
            if (s[i]==s[i-1]) ++power;
            else {
                if (power>max_power) {
                    max_power=power; 
                }
                power=1;
            }
        }
        if (power>max_power) {
            max_power=power;
        }
        return max_power;
    }
};
int main() {
    return 0;
}