class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int sr = -1, sc = -1;   // start position
        int totalKeys = 0;      // total keys count

        // ================= REPEAT HOTA HAI =================
        // grid scan krke start point aur required info nikalna
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '@') {
                    sr = i;
                    sc = j;
                }

                // ================= PROBLEM SPECIFIC =================
                // kitni keys h ye nikal rhe
                else if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    totalKeys = max(totalKeys,
                                    grid[i][j] - 'a' + 1);
                }
            }
        }

        // ================= BITMASK TEMPLATE =================
        // agar k keys hain to sab collect hone pr mask
        // ex k=3 => 111 = 7
        int allKeysMask = (1 << totalKeys) - 1;

        // ================= BFS + STATE TEMPLATE =================
        // visited[r][c][mask]
        // same cell dubara aa skta h
        // lekin alag mask ke saath
        vector<vector<vector<bool>>> visited(
            m,
            vector<vector<bool>>(
                n,
                vector<bool>(1 << totalKeys, false)
            )
        );

        // ================= BFS TEMPLATE =================
        // row, col, keyMask, distance
        queue<tuple<int,int,int,int>> q;

        q.push({sr, sc, 0, 0});
        visited[sr][sc][0] = true;

        // ================= GRID BFS TEMPLATE =================
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        // ================= BFS TEMPLATE =================
        while (!q.empty()) {

            auto [r, c, mask, dist] = q.front();
            q.pop();

            // ================= GOAL CHECK =================
            // saari keys mil gayi
            if (mask == allKeysMask)
                return dist;

            // ================= GRID BFS TEMPLATE =================
            for (int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                // ================= BOUNDARY CHECK TEMPLATE =================
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                char ch = grid[nr][nc];

                // ================= WALL CHECK =================
                if (ch == '#')
                    continue;

                // ================= STATE COPY TEMPLATE =================
                // next state banane se pehle current state copy
                int newMask = mask;

                // =====================================================
                // ================= PROBLEM SPECIFIC ==================
                // =====================================================

                // key mili
                if (ch >= 'a' && ch <= 'f') {

                    // key collect krlo
                    // ex: b mila => bit 1 set
                    newMask |= (1 << (ch - 'a'));
                }

                // lock mila
                if (ch >= 'A' && ch <= 'F') {

                    int need = ch - 'A';

                    // corresponding key nhi hai
                    // to lock cross nhi kr skte
                    if ((mask & (1 << need)) == 0)
                        continue;
                }

                // =====================================================
                // ================= BFS TEMPLATE =======================
                // =====================================================

                // same state pe pehle nhi aaye
                if (!visited[nr][nc][newMask]) {

                    visited[nr][nc][newMask] = true;

                    q.push({
                        nr,
                        nc,
                        newMask,
                        dist + 1
                    });
                }
            }
        }

        // saari keys collect nhi ho paayi
        return -1;
    }
};