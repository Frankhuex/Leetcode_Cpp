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
    bool detectCapitalUse(string word) {
        if (isUpper(word[0])) {
            if (isUpper(word[1])) {
                for (int i=2;i<word.size();i++) {
                    if (!isUpper(word[i])) {
                        return false;
                    }
                }
                return true;
            }
            if (!isUpper(word[1])) {
                for (int i=2;i<word.size();i++) {
                    if (isUpper(word[i])) {
                        return false;
                    }
                }
                return true;
            }
        }
        if (!isUpper(word[0])) {
            for (int i=1;i<word.size();i++) {
                if (isUpper(word[i])) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
private:
    bool isUpper(char c) {
        if (c>='A' && c<='Z') return true;
        else return false;
    }
};
int main() {
    return 0;
}