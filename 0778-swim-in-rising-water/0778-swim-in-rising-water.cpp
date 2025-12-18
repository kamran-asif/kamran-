class Solution {
private:
    int dx[4] = {-1, 0, 1, 0};  // up, right, down, left
    int dy[4] = {0, 1, 0, -1};
    
    bool isFeasible(vector<vector<int>>& grid, int t) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        
        if (grid[0][0] > t) return false;  // strt cell mst be valid
        q.push({0, 0});
        visited[0][0] = true;
        
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            if (i == n-1 && j == n-1) return true;  // reached end
            
            // 4-directional bfS
            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d], nj = j + dy[d];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && 
                    !visited[ni][nj] && grid[ni][nj] <= t) {
                    visited[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }
        return false;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = grid[0][0], right = 0;  // binary search bounds
        
        // find max possible time needed
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                right = max(right, grid[i][j]);
            }
        }
       
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isFeasible(grid, mid)) {
                right = mid;
            } else {
                left = mid + 1;  
            }
        }
        return left;
    }
};
