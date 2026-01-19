
class Solution {
public:
    int profitableSchemes(int n, int minProfit,
                          vector<int>& group,
                          vector<int>& profit) {

        const int MOD = 1e9 + 7;

        // dp[j][k]=number of ways using j members with profit k
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));

        // base case
        dp[0][0] = 1;

        int m = group.size();

        for (int i = 0; i < m; i++) {
            int g = group[i];
            int p = profit[i];

            // 0/1 knapsack->iterate backwards
            for (int j = n; j >= g; j--) {
                for (int k = minProfit; k >= 0; k--) {
                    int newProfit = min(minProfit, k + p);
                    dp[j][newProfit] =
                        (dp[j][newProfit] + dp[j - g][k]) % MOD;
                }
            }
        }

        // sum all ways where profit>=minProfit
        int result = 0;
        for (int j = 0; j <= n; j++) {
            result = (result + dp[j][minProfit]) % MOD;
        }

        return result;
    }
};
