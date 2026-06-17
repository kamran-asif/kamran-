class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();

        // Impossible to end with exactly one pile
        if ((n - 1) % (k - 1) != 0)
            return -1;

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stones[i];
        }

        auto rangeSum = [&](int l, int r) {
            return prefix[r + 1] - prefix[l];
        };

        const int INF = 1e9;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                dp[i][j] = INF;

                for (int mid = i; mid < j; mid += (k - 1)) {
                    dp[i][j] = min(dp[i][j],
                                   dp[i][mid] + dp[mid + 1][j]);
                }

                // Can this interval be merged into one pile?
                if ((j - i) % (k - 1) == 0) {
                    dp[i][j] += rangeSum(i, j);
                }
            }
        }

        return dp[0][n - 1];
    }
};