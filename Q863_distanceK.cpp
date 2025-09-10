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
#include <unordered_map>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<int> ans;
    unordered_set<TreeNode*> visited;
    unordered_map<TreeNode*,TreeNode*> parent;
    TreeNode* root;

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        this->root=root;
        dfsFindParent(root);
        dfs(target,k);
        return ans;
    }

    void dfsFindParent(TreeNode* root) {
        if (root==nullptr) return;
        parent[root->left]=root;
        dfsFindParent(root->left);
        parent[root->right]=root;
        dfsFindParent(root->right);
        
    }

    void dfs(TreeNode* target, int k) {
        if (target==nullptr || visited.count(target)) return;
        visited.insert(target);
        if (k==0) {
            ans.push_back(target->val);
            return;
        }
        if (target!=root) {
            dfs(parent[target],k-1);
        }
        dfs(target->left,k-1);
        dfs(target->right,k-1);
    }

};
int main() {
    return 0;
}