class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        int targetMask = (1 << n) - 1;

        queue<pair<int,int>> q;

        vector<vector<bool>> visited(
            n,
            vector<bool>(1 << n, false)
        );

        // Multi-source BFS
        for (int i = 0; i < n; i++) {
            int mask = (1 << i);

            q.push({i, mask});
            visited[i][mask] = true;
        }

        int steps = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [node, mask] = q.front();
                q.pop();

                if (mask == targetMask)
                    return steps;

                for (int neigh : graph[node]) {

                    int nextMask =
                        mask | (1 << neigh);

                    if (!visited[neigh][nextMask]) {

                        visited[neigh][nextMask] = true;

                        q.push({neigh, nextMask});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};