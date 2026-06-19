class Solution {
public:// hmesha dhyan rkhna ki ye robot or matrix rhe to dp hi lgega bottom up sp
    int cherryPickup(vector<vector<int>>& grid) {

        int rows = grid.size();      // total rows
        int cols = grid[0].size();  // total columns

        // next[c1][c2] => next row se maximum cherries
        // agar robot1 column c1 par hai aur robot2 column c2 par hai
        vector<vector<int>> next(cols, vector<int>(cols, 0));

        // ================= BASE CASE =================
        // Last row ke liye answer direct calculate kar sakte hain
        // kyunki uske neeche koi row nahi hai.

        for (int c1 = 0; c1 < cols; c1++) {
            for (int c2 = 0; c2 < cols; c2++) {

                // Agar dono robots same cell par hain
                // to cherry sirf ek baar count hogi
                if (c1 == c2)
                    next[c1][c2] = grid[rows - 1][c1];

                // Warna dono alag cells ki cherries collect karenge
                else
                    next[c1][c2] =
                        grid[rows - 1][c1] + grid[rows - 1][c2];
            }
        }

        // ================= DP START =================
        // Bottom-up approach:
        // last row se upar ki taraf chalenge

        for (int r = rows - 2; r >= 0; r--) {

            // Current row ke answers store karne ke liye
            vector<vector<int>> curr(cols, vector<int>(cols, 0));

            // Robot1 ki position
            for (int c1 = 0; c1 < cols; c1++) {

                // Robot2 ki position
                for (int c2 = 0; c2 < cols; c2++) {

                    // Current row ki cherries collect karo

                    int cherries;

                    // Agar dono same cell par hain
                    // to ek hi baar count karenge
                    if (c1 == c2)
                        cherries = grid[r][c1];
                    else
                        cherries = grid[r][c1] + grid[r][c2];

                    // Next row se best answer store karega
                    int best = 0;

                    // Robot1 ke 3 possible moves:
                    // left diagonal (-1)
                    // straight (0)
                    // right diagonal (+1)

                    for (int d1 = -1; d1 <= 1; d1++) {

                        // Robot2 ke bhi 3 possible moves

                        for (int d2 = -1; d2 <= 1; d2++) {

                            // Next position of robot1
                            int nc1 = c1 + d1;

                            // Next position of robot2
                            int nc2 = c2 + d2;

                            // Check karo ki grid ke bahar to nahi ja rahe
                            if (nc1 >= 0 && nc1 < cols &&
                                nc2 >= 0 && nc2 < cols) {

                                // Next row ke saare valid options me
                                // maximum answer choose karo

                                best = max(best, next[nc1][nc2]);
                            }
                        }
                    }

                    // Current cherries +
                    // next row ka best possible answer

                    curr[c1][c2] = cherries + best;
                }
            }

            // Current row ab next row ban jayegi
            // kyunki hum upar move kar rahe hain

            next = move(curr);
        }

        // Initial state:
        // Robot1 => column 0
        // Robot2 => last column

        return next[0][cols - 1];
    }
};
//har state (r,c1,c2) se hum 9 possible next states check karte hain aur jo maximum cherries deta hai usko choose karte hain. This is the core idea of the DP.