class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        // add 1 at bth ends
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        // dp tble
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        // lngth of intrvl
        for (int len = 2; len <= n + 1; len++) {
            for (int i = 0; i + len <= n + 1; i++) {
                int j = i + len;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = max(
                        dp[i][j],
                        dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]
                    );
                }
            }
        }
        
        return dp[0][n + 1];
    }
};