class Solution {
public:
using ll=long long;
const ll INF=(1LL<60);
    int climbStairs(int n, vector<int>& costs) {
       using ll = long long;
    const ll INF = (1LL << 60);
        vector<ll> dp(n + 1, INF);
        dp[0] = 0;

        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= 3; ++k) {
                int i = j - k;
                if (i < 0) break;
                ll cand = dp[i] + (ll)costs[j - 1] + 1LL * k * k;
                dp[j] = min(dp[j], cand);
            }
        }
        return dp[n];
    
    }
    
};