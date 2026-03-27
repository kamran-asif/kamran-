class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size();
    int n = dungeon[0].size();
    
    // Modify the dungeon matrix itself to save space
    dungeon[m-1][n-1] = max(1, 1 - dungeon[m-1][n-1]);
    
    // Fill the last row (bottom row)
    for(int i = m-2; i >= 0; i--) {
        dungeon[i][n-1] = max(1, dungeon[i+1][n-1] - dungeon[i][n-1]);
    }
    
    // Fill the last column (rightmost column)
    for(int j = n-2; j >= 0; j--) {
        dungeon[m-1][j] = max(1, dungeon[m-1][j+1] - dungeon[m-1][j]);
    }
    
    // Fill the rest of the dungeon matrix from bottom-right to top-left
    for(int i = m-2; i >= 0; i--) {
        for(int j = n-2; j >= 0; j--) {
            int right = max(1, dungeon[i][j+1] - dungeon[i][j]);
            int down = max(1, dungeon[i+1][j] - dungeon[i][j]);
            dungeon[i][j] = min(right, down);
        }
    }
    
    // The minimum health required at the start position (0,0)

     return dungeon[0][0];
    }

};
