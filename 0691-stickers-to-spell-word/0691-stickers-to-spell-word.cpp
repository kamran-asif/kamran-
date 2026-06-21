class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {

        int n = target.size();

        // Total possible states = 2^n
        int N = 1 << n;

        // dp[mask] = minimum stickers needed
        // to create characters represented by mask
        vector<int> dp(N, INT_MAX);

        // base state
        dp[0] = 0;

        // ============================
        // BITMASK DP LOOP (REPEATED PATTERN)
        // ============================
        for(int mask = 0; mask < N; mask++)
        {
            // unreachable state
            if(dp[mask] == INT_MAX)
                continue;

            // ============================
            // TRANSITION TRY KARO
            // ============================
            for(string &sticker : stickers)
            {
                // current state se start
                int newMask = mask;

                // sticker ke har character ko use karo
                for(char c : sticker)
                {
                    // target me matching unfilled character dhoondo
                    for(int i = 0; i < n; i++)
                    {
                        // already filled hai
                        if(newMask & (1 << i))
                            continue;

                        // matching character mil gaya
                        if(target[i] == c)
                        {
                            // us position ko fill mark karo
                            newMask |= (1 << i);

                            // ye sticker ka character ek hi baar use hoga
                            break;
                        }
                    }
                }

                // ============================
                // DP RELAXATION (REPEATED PATTERN)
                // ============================
                dp[newMask] =
                    min(dp[newMask],
                        dp[mask] + 1);
            }
        }

        // full mask = saare characters complete
        return dp[N-1] == INT_MAX
                    ? -1
                    : dp[N-1];
    }
};