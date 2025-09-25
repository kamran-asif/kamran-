class Solution {
public:
    int ans = 0;  
    void dfs(int node, int parent, vector<vector<pair<int,int>>>& adj) {
        for (auto [nbr, dir] : adj[node]) {
            if (nbr == parent) continue;
            if (dir == 1) ans++;
            dfs(nbr, node, adj);
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : connections) {
            int u = e[0], v = e[1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }
        dfs(0, -1, adj);
        return ans;
    }
};
