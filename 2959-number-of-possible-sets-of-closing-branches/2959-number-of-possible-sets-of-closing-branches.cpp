class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        const long long INF = (long long)1e15;
        int ans = 0;
        int total = 1 << n;

        for (int mask = 0; mask < total; ++mask) {
       if (mask == 0) { 
                ans++; 
                continue; 
            }
            vector<vector<long long>> d(n, vector<long long>(n, INF));
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) d[i][i] = 0;
            }
            for (auto &e : roads) {
                int u = e[0], v = e[1], w = e[2];
                if ((mask & (1 << u)) && (mask & (1 << v))) {
                    d[u][v] = min(d[u][v], (long long)w);
                    d[v][u] = min(d[v][u], (long long)w);
                }
            }
            for (int k = 0; k < n; ++k) {
                if (!(mask & (1 << k))) continue;
                for (int i = 0; i < n; ++i) {
                    if (!(mask & (1 << i))) continue;
                    if (d[i][k] == INF) continue;
                    for (int j = 0; j < n; ++j) {
                        if (!(mask & (1 << j))) continue;
                        if (d[k][j] == INF) continue;
                        long long nd = d[i][k] + d[k][j];
                        if (nd < d[i][j]) d[i][j] = nd;
                    }
                }
            }
            bool ok = true;
            for (int i = 0; i < n && ok; ++i) {
                if (!(mask & (1 << i))) continue;
                for (int j = i + 1; j < n; ++j) {
                    if (!(mask & (1 << j))) continue;
                    if (d[i][j] == INF || d[i][j] > maxDistance) { ok = false; break; }
                }
            }
            if (ok) ++ans;
        }

        return ans;
    }
};
