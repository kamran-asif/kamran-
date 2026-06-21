class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {

        int n = target.size();

        int N = 1 << n;

        vector<int> dp(N, INT_MAX);

        dp[0] = 0;

        for(int mask = 0; mask < N; mask++)
        {
            if(dp[mask] == INT_MAX)
                continue;

            for(string &sticker : stickers)
            {
                int newMask = mask;

                for(char c : sticker)
                {
                    for(int i = 0; i < n; i++)
                    {
                        // already filled
                        if(newMask & (1 << i))
                            continue;

                        if(target[i] == c)
                        {
                            newMask |= (1 << i);
                            break; // use this character once
                        }
                    }
                }

                dp[newMask] =
                    min(dp[newMask],
                        dp[mask] + 1);
            }
        }

        return dp[N-1] == INT_MAX
                    ? -1
                    : dp[N-1];
    }
};