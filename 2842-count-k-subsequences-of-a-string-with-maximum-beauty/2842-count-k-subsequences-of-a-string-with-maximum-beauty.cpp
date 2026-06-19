#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    long long C[27][27];
    
    // Precompute combinations (nCr) using Pascal's Triangle
    void buildCombinations() {
        for (int i = 0; i <= 26; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 1000000007;
            }
        }
    }

public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        long long MOD = 1e9 + 7;
        
        // Step 1: Count frequency of each character
        vector<long long> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        // Extract non-zero frequencies
        vector<long long> counts;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                counts.push_back(freq[i]);
            }
        }
        
        // Edge Case: Not enough unique characters to form a k-subsequence
        if (counts.size() < k) return 0;
        
        // Step 2: Sort frequencies descending to greedily pick highest
        sort(counts.rbegin(), counts.rend());
        
        // Identify the cut-off frequency boundary
        long long X = counts[k - 1]; 
        
        long long greater_count = 0; // Chars with freq > X
        long long equal_count = 0;   // Chars with freq == X
        
        for (long long c : counts) {
            if (c > X) greater_count++;
            else if (c == X) equal_count++;
        }
        
        // How many chars of frequency X do we actually need to reach exactly k chars?
        long long needed = k - greater_count;
        
        // Precompute nCr values up to 26
        buildCombinations();
        
        long long ans = 1;
        
        // Step 3: Multiply the ways to pick the mandatory elements (freq > X)
        for (int i = 0; i < greater_count; i++) {
            ans = (ans * counts[i]) % MOD;
        }
        
        // Step 4: Multiply by the number of ways to choose 'needed' elements out of 'equal_count'
        ans = (ans * C[equal_count][needed]) % MOD;
        
        // Step 5: Multiply the ways to pick those chosen 'needed' elements from the string
        for (int i = 0; i < needed; i++) {
            ans = (ans * X) % MOD;
        }
        
        return ans;
    }
};