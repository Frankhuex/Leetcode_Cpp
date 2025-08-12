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

    string decodeString(string s) {
        string stack="";
        bool foundFrontBracket=false;
        while (!s.empty()) {
            char c=s.back();
            s.pop_back();
            if (!isDigit(c) && foundFrontBracket) {
                changeStack(stack);
                foundFrontBracket=false;
            }
            if (c=='[') {
                foundFrontBracket=true;
            }
            stack.push_back(c);
            cout<<stack<<endl;
        }
        changeStack(stack);
        string ans="";
        while (!stack.empty()) {
            char c=stack.back();
            stack.pop_back();
            ans.push_back(c);
        }
        return ans;
    }

    bool isDigit(char c) {
        return c>='0' && c<='9';
    }

    bool isLetter(char c) {
        return c>='a' && c<='z';
    }

    void changeStack(string& stack) {
        if (!stack.empty() && isDigit(stack.back())) {
            int num=0;
            string sub="";
            while (!stack.empty()) {
                char c1=stack.back();
                stack.pop_back();
                if (isDigit(c1)) {
                    num=10*num+(c1-'0');
                } else if (isLetter(c1)) {
                    sub.push_back(c1);
                } else if (c1==']') {
                    for (int i=0;i<num;++i) {
                        for (int j=sub.size()-1;j>=0;--j) {
                            stack.push_back(sub[j]);
                        }
                    }
                    break;
                }
            }
        }
    }
};

int main() {
    return 0;
}