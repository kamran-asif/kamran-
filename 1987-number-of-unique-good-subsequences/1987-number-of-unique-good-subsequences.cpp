

class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        const int MOD = 1e9 + 7;

        long long end0 = 0;   // unique good subsequences ending with '0'
        long long end1 = 0;   // unique good subsequences ending with '1'
        bool hasZero = false; // whether "0" exists

        for (char c : binary) {
            if (c == '1') {
                // New subsequences ending with 1:
                // append '1' to all existing good subsequences + "1"
                end1 = (end0 + end1 + 1) % MOD;
            } else {
                // New subsequences ending with 0:
                // append '0' to all existing good subsequences
                end0 = (end0 + end1) % MOD;
                hasZero = true;
            }
        }

        return (end0 + end1 + (hasZero ? 1 : 0)) % MOD;
    }
};