
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size();
        int n = board[0].size();
        int r = click[0], c = click[1];
        
        // Agar clicked cell mine ('M') hai, game over, 'X' kar do
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }
        
        // Otherwise, start DFS/BFS reveal
        dfs(board, r, c, m, n);
        return board;
    }
    
private:
    // 8 direction vectors
    const int dr[8] = {-1,-1,-1,0,0,1,1,1};
    const int dc[8] = {-1,0,1,-1,1,-1,0,1};
    
    void dfs(vector<vector<char>>& board, int r, int c, int m, int n) {
        // Boundary check aur already revealed toh return
        if (r<0 || r>=m || c<0 || c>=n || board[r][c] != 'E') return;
        
        // Count karein aas-paas kitni mines hain
        int mines = 0;
        for (int i = 0; i < 8; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc] == 'M') {
                mines++;
            }
        }
        
        // Agar adjacent mines > 0 hain, toh cell pe digit likho aur stop recursion
        if (mines > 0) {
            board[r][c] = char('0' + mines);
        } else {
            // Else blank ('B') mark karo aur sab neighbours recursively reveal karo
            board[r][c] = 'B';
            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                dfs(board, nr, nc, m, n);
            }
        }
    }
};

