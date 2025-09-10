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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generate(1,n);
    }

    vector<TreeNode*> generate(int start, int end) {
        if (start>end) return vector<TreeNode*>{nullptr};
        if (start==end) return vector<TreeNode*>{new TreeNode(start)};
        vector<TreeNode*> ans;
        for (int n=start;n<=end;n++) {
            vector<TreeNode*> left=generate(start,n-1);
            vector<TreeNode*> right=generate(n+1,end);
            for (TreeNode* tl: left) {
                for (TreeNode* tr: right) {
                    TreeNode* rt=new TreeNode(n,tl,tr);
                    ans.push_back(rt);
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}