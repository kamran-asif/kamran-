class Solution {
const int maxi = INT_MAX;
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dp(m,vector<int>(n,maxi));
        dp[0][0] = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 && j == 0)    
                    continue;
                if(i-1 >= 0)
                    dp[i][j] = min(dp[i][j] , grid[i][j] + dp[i-1][j]);
                if(j-1 >= 0)
                    dp[i][j] = min(dp[i][j] , grid[i][j] + dp[i][j-1]);
            }
        }

        while(k--){
            const int limit = 1e4;
            vector<int>tp(limit+1,maxi);
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    tp[grid[i][j]] = min(dp[i][j] , tp[grid[i][j]]);
                }
            }

            for(int i = limit-1;i>=0;i--)
                tp[i] = min(tp[i],tp[i+1]);

            vector<vector<int>> temp(m,vector<int>(n,maxi));
            temp[0][0] = 0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(i == 0 && j==0)
                        continue;
                    temp[i][j] = tp[grid[i][j]];
                    if(i-1 >= 0 )
                        temp[i][j] = min(temp[i][j] , grid[i][j] + temp[i-1][j]);
                    if(j-1 >= 0)
                        temp[i][j] = min(temp[i][j] , grid[i][j] + temp[i][j-1]);
                }
            }

            dp = temp;
        }


        return dp[m-1][n-1];
    }
};