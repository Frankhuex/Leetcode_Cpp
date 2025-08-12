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
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int maxPrice=0;
        for (int i=prices.size()-1;i>=0;--i) {
            maxPrice=max(maxPrice,prices[i]);
            maxProfit=max(maxProfit,maxPrice-prices[i]);
        }
        return maxProfit;
    }
};

int main() {
    return 0;
}