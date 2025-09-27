class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> deg(n, 0);
        vector<vector<int>> connected(n, vector<int>(n, 0));

        for (const auto &r : roads) {
            int a = r[0];
            int b = r[1];
            deg[a]++;
            deg[b]++;
            connected[a][b] = 1;
            connected[b][a] = 1;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) { 
                int rank = deg[i] + deg[j] - connected[i][j];
                ans = max(ans, rank);
            }
        }
        return ans;
    }
};
