class Solution {
    // memo[index][diff][is_less][is_started][pos_count]
    long long memo[20][200][2][2][20]; 
    const int OFFSET = 100;

    long long dp(int idx, int diff, bool is_less, bool is_started, int pos_count, const string& s) {
        if (idx == s.length()) {
            // Requirement: At least two digits and diff == 0
            return (is_started && diff == 0 && pos_count >= 2) ? 1 : 0;
        }

        if (memo[idx][diff + OFFSET][is_less][is_started][pos_count] != -1) {
            return memo[idx][diff + OFFSET][is_less][is_started][pos_count];
        }

        long long count = 0;
        int limit = is_less ? 9 : (s[idx] - '0');

        for (int d = 0; d <= limit; ++d) {
            bool next_less = is_less || (d < limit);
            if (!is_started && d == 0) {
                // Keep looking for the first non-zero digit
                count += dp(idx + 1, 0, next_less, false, 0, s);
            } else {
                // pos_count + 1 because the first digit is position 1 (odd)
                int next_diff = diff + (((pos_count + 1) % 2 != 0) ? d : -d);
                count += dp(idx + 1, next_diff, next_less, true, pos_count + 1, s);
            }
        }

        return memo[idx][diff + OFFSET][is_less][is_started][pos_count] = count;
    }

    long long helper(long long val) {
        if (val < 0) return 0;
        string s = to_string(val);
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, false, false, 0, s);
    }

public:
    // IMPORTANT: Return type must be long long to avoid overflow
    long long countBalanced(long long low, long long high) {
        return helper(high) - helper(low - 1);
    }
};