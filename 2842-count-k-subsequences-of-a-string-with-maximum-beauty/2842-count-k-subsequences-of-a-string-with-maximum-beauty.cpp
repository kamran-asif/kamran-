#include <bits/stdc++.h>
using namespace std;

class Solution {
    static const long long MOD = 1e9 + 7;

    // Fast modular exponentiation
    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }

    // Precompute factorials and inverse factorials for C(n, r)
    vector<long long> fact, inv_fact;

    void precompute(int n) {
        fact.resize(n + 1);
        inv_fact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % MOD;
        inv_fact[n] = power(fact[n], MOD - 2, MOD);
        for (int i = n - 1; i >= 0; i--)
            inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }

    // Combination C(n, r) mod p
    long long C(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] % MOD * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
    }

public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        // Step 1: Frequency count
        int freq[26] = {};
        for (char c : s) freq[c - 'a']++;

        // Step 2: Collect non-zero frequencies
        vector<int> freqs;
        for (int i = 0; i < 26; i++)
            if (freq[i] > 0) freqs.push_back(freq[i]);

        int distinct = freqs.size();

        // Edge case: not enough distinct chars to form k-subsequence
        if (distinct < k) return 0;

        // Edge case: k == 0 → 1 empty subsequence
        if (k == 0) return 1;

        // Step 3: Sort descending
        sort(freqs.begin(), freqs.end(), greater<int>());

        // Step 4: Precompute factorials up to distinct (max n for C(n,r))
        precompute(distinct);

        // Step 5: Greedily pick top-k characters
        long long ans = 1;
        int remaining = k;

        int i = 0;
        while (i < distinct && remaining > 0) {
            int cur_freq = freqs[i];

            // Count how many chars share this exact frequency (tie group)
            int j = i;
            while (j < distinct && freqs[j] == cur_freq) j++;
            int group_size = j - i;  // number of chars with this frequency

            if (group_size <= remaining) {
                // Take ALL chars in this group
                // Each char contributes cur_freq ways (pick 1 of cur_freq positions)
                // → multiply by cur_freq^group_size
                ans = ans % MOD * power(cur_freq, group_size, MOD) % MOD;
                remaining -= group_size;
            } else {
                // Tie boundary: need 'remaining' out of 'group_size' chars
                // Ways = C(group_size, remaining) * cur_freq^remaining
                ans = ans % MOD
                    * C(group_size, remaining) % MOD
                    * power(cur_freq, remaining, MOD) % MOD;
                remaining = 0;
            }

            i = j;  // move to next group
        }

        return (int)(ans % MOD);
    }
};