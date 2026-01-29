class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const long long inf = 1e18;
        vector<vector<long long>> c(26, vector<long long>(26, inf));
        int m = original.size();

        for (int i = 0; i < 26; i++)
            c[i][i] = 0;

        for (int i = 0; i < m; i++) {
            c[original[i] - 'a'][changed[i] - 'a'] =
                min(c[original[i] - 'a'][changed[i] - 'a'], 1LL * cost[i]);
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
                }
            }
        }

        long long ans = 0;
        int n = source.length();

        for (int i = 0; i < n; i++) {
            ans += c[source[i] - 'a'][target[i] - 'a'];
            if (ans >= inf) return -1;
        }

        return ans;
    }
};
