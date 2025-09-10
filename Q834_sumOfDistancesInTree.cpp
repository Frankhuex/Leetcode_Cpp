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
private:
    vector<int> ans;
    vector<int> dp; //该节点为根的子树所有节点到根距离和
    vector<int> sz; //该节点为根的子树大小
    vector<vector<int>> graph;

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        ans.resize(n,0);
        dp.resize(n,0);
        sz.resize(n,1);
        graph.resize(n,{});
        for (vector<int>& edge: edges) {
            int u=edge[0],v=edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs1(0,-1);
        dfs2(0,-1);
        return ans;
    }

    void dfs1(int u, int parent) {
        sz[u]=1;
        dp[u]=0;
        for (int& v: graph[u]) {
            if (v==parent) continue;
            dfs1(v,u);
            dp[u]+=dp[v]+sz[v];
            sz[u]+=sz[v];
        }
    }

    void dfs2(int u, int parent) {
        ans[u]=dp[u];
        for (int& v: graph[u]) {
            if (v==parent) continue;
            int dpu=dp[u],dpv=dp[v],szu=sz[u],szv=sz[v];
            dp[u]-=dp[v]+sz[v];
            sz[u]-=sz[v];
            dp[v]+=dp[u]+sz[u];
            sz[v]+=sz[u];
            dfs2(v,u); //因为开头使用了保存的dp[u]，所以dp[u]要传下去后回溯
            dp[u]=dpu,dp[v]=dpv,sz[u]=szu,sz[v]=szv;
        }
    }
};

int main() {
    return 0;
}