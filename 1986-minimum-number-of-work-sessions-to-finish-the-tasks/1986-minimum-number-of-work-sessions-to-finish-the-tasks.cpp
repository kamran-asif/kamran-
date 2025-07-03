class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();                            // n mein total tasks ka count store kiya
        int N = 1 << n;                                  // N = 2^n, jitne subsets honge
        vector<int> sum(N, 0);                           // sum[mask] mein mask subset ka total time

        // Har subset ka total time precompute karte hain
        for (int mask = 1; mask < N; ++mask) {
            int lsb = __builtin_ctz(mask);               // mask ka least significant set bit ka index
            int prev = mask ^ (1 << lsb);                // prev subset nikal liya jahan woh bit na ho
            sum[mask] = sum[prev] + tasks[lsb];          // current subset time = prev subset + is task ka time
        }
        
        const int INF = 1e9;                             // ek bahut bada number, practically infinite
        vector<int> dp(N, INF);                          // dp[mask] = min sessions to finish tasks in mask
        dp[0] = 0;                                       // mask=0 (koi task nahi) => 0 sessions chahiye
        
        // Bitmask DP: har mask ke liye answer nikalenge
        for (int mask = 1; mask < N; ++mask) {
            // mask ke saare non-empty submasks iterate karo
            for (int sub = mask; sub; sub = (sub - 1) & mask) {
                // agar submask ke tasks ek session mein fit ho jate hain
                if (sum[sub] <= sessionTime) {
                    // baaki tasks wale mask minus submask ke liye dp value + 1 session
                    dp[mask] = min(dp[mask], dp[mask ^ sub] + 1);
                }
            }
        }
        
        return dp[N - 1];                                // full set ke liye minimum sessions
    }
};
