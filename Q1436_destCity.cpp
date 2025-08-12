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
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> dep,dest;
        for (auto &city:paths) {
            dep.insert(city[0]);
        }
        for (auto &city:paths) {
            if (!dep.count(city[1])) {
                return city[1];
            }
        }
        return "";
    }
};
int main() {
    return 0;
}