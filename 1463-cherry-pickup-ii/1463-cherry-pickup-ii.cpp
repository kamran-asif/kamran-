class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> next(cols, vector<int>(cols, 0));

        // Base row
        for (int c1 = 0; c1 < cols; c1++) {
            for (int c2 = 0; c2 < cols; c2++) {
                if (c1 == c2)
                    next[c1][c2] = grid[rows - 1][c1];
                else
                    next[c1][c2] = grid[rows - 1][c1] + grid[rows - 1][c2];
            }
        }

        for (int r = rows - 2; r >= 0; r--) {
            vector<vector<int>> curr(cols, vector<int>(cols, 0));

            for (int c1 = 0; c1 < cols; c1++) {
                for (int c2 = 0; c2 < cols; c2++) {

                    int cherries =
                        (c1 == c2)
                            ? grid[r][c1]
                            : grid[r][c1] + grid[r][c2];

                    int best = 0;

                    for (int d1 = -1; d1 <= 1; d1++) {
                        for (int d2 = -1; d2 <= 1; d2++) {

                            int nc1 = c1 + d1;
                            int nc2 = c2 + d2;

                            if (nc1 >= 0 && nc1 < cols &&
                                nc2 >= 0 && nc2 < cols) {
                                best = max(best, next[nc1][nc2]);
                            }
                        }
                    }

                    curr[c1][c2] = cherries + best;
                }
            }

            next = move(curr);
        }

        return next[0][cols - 1];
    }
};