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

class Solution1 {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int left=0;
        while (left<s.size()) {
            int length=maxFirstLength(s,left);
            ans.push_back(length);
            left+=length;
        }
        return ans;
    }

    int maxFirstLength(string s, int left) {
        if (left>=s.size()) return 0;
        vector<char> charList;
        unordered_set<char> charSet;
        charList.push_back(s[left]);
        charSet.insert(s[left]);
        int check=0; // For charList
        int right=left;
        
        while (1) {
            if (right>=s.size() || check>=charList.size()) {
                break;
            }

            int left1=right+1;
            for (int i=left1;i<s.size();++i) {
                if (s[i]==charList[check]) {
                    right=i;
                }
            }

            for (int i=left1;i<=right-1;++i) {
                if (!charSet.count(s[i])) {
                    charSet.insert(s[i]);
                    charList.push_back(s[i]);
                }
            }
            
            ++check;
        }

        return right-left+1;

    }
};

class Solution2 {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int last[26];
        for (int i=0;i<s.size();++i) {
            last[s[i]-'a']=i;
        }
        int start=0,end=0;
        for (int i=0;i<s.size();++i) {
            end=max(end,last[s[i]-'a']);
            if (i==end) {
                ans.push_back(end-start+1);
                start=++end;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}