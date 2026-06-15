class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {

        int n = stoneValue.size();

        int dp1 = 0; // dp[i+1]
        int dp2 = 0; // dp[i+2]
        int dp3 = 0; // dp[i+3]

        for (int i = n - 1; i >= 0; i--) {

            int sum = 0;
            int cur = INT_MIN;

            sum += stoneValue[i];
            cur = max(cur, sum - dp1);

            if (i + 1 < n) {
                sum += stoneValue[i + 1];
                cur = max(cur, sum - dp2);
            }

            if (i + 2 < n) {
                sum += stoneValue[i + 2];
                cur = max(cur, sum - dp3);
            }

            dp3 = dp2;
            dp2 = dp1;
            dp1 = cur;
        }

        if (dp1 > 0) return "Alice";
        if (dp1 < 0) return "Bob";
        return "Tie";
    }
};