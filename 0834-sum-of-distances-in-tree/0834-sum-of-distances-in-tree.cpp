class Solution {
public:
    vector<vector<int>> tree;
    vector<int> subtreeSize;
    vector<int> dp;
    vector<int> answer;
    int n;

    void dfs1(int u, int parent) {
        subtreeSize[u] = 1;
        for (int v : tree[u]) {
            if (v == parent) continue;
            dfs1(v, u);
            subtreeSize[u] += subtreeSize[v];
            dp[u] += dp[v] + subtreeSize[v];
        }
    }

    void dfs2(int u, int parent) {
        for (int v : tree[u]) {
            if (v == parent) continue;
            answer[v] = answer[u] - subtreeSize[v] + (n - subtreeSize[v]);
            dfs2(v, u);
        }
    }

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        n = N;
        tree.assign(n, {});
        subtreeSize.assign(n, 0);
        dp.assign(n, 0);
        answer.assign(n, 0);

        for (auto &e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        dfs1(0, -1);
        answer[0] = dp[0];
        dfs2(0, -1);

        return answer;
    }
};
