#include <bits/stdc++.h>
using namespace std;
class Solution {public:
    int numDistinct(string s, string t) {
       int m = s.size(), n = t.size();
   // Edge cases
     if (n > m) return 0;          // t longer than s → impossible
        if (n == 0) return 1;          // empty t is subseq of anything (1 way)
        if (m == 0) return 0;          // non-empty t, empty s → impossible

        // dp[j] = # ways to form t[0..j-1] from s processed so far
        // Use long to avoid overflow mid-computation, cap at INT_MAX
        vector<long> dp(n + 1, 0);
        dp[0] = 1;  // empty subsequence: always 1 way

        for (int i = 0; i < m; i++) {
            // Right-to-left to avoid counting s[i] twice
            for (int j = n; j >= 1; j--) {
                if (s[i] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                    // Clamp to prevent overflow (answer fits in int32)
                    if (dp[j] > INT_MAX) dp[j] = INT_MAX;
                }
            }
        }

        return (int)dp[n];
    }
};
