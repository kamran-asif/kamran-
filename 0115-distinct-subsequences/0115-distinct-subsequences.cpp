class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        // Edge Case 1: If t is longer than s, it's impossible to form t as a subsequence
        if (n > m) return 0;
        
        // Edge Case 2: If s is identical to t, there is exactly 1 way
        if (s == t) return 1;
        
        // DP array initialized to 0. 
        // We use unsigned long long to prevent integer overflow during intermediate calculations.
        // Even though the final answer fits in a 32-bit int, intermediate paths can exceed it.
        vector<unsigned long long> dp(n + 1, 0);
        
        // Base case: An empty string t (length 0) can be formed in exactly 1 way
        // by deleting all characters from s.
        dp[0] = 1;
        
        // Iterate through every character in s
        for (int i = 1; i <= m; ++i) {
            // Iterate backwards through t to calculate the DP states
            // We stop at 1 because dp[0] is always 1 (base case)
            for (int j = n; j >= 1; --j) {
                // If characters match, add the ways to form the prefix of t
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j] + dp[j - 1];
                }
            }
        }
        
        // The answer fits in a 32-bit signed integer as per problem constraints
        return static_cast<int>(dp[n]);
    }
};