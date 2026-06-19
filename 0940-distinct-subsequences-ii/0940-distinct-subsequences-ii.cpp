#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        long long MOD = 1e9 + 7;
        
        // Array to store the number of distinct subsequences ending with each character ('a' to 'z')
        vector<long long> ends(26, 0);
        
        // Total number of distinct non-empty subsequences
        long long tot = 0;
        
        for (char c : s) {
            int idx = c - 'a';
            
            // Calculate newly added subsequences
            // tot + 1: Append 'c' to all existing subsequences + the subsequence "c" itself
            // - ends[idx]: Subtract the duplicates that already end in 'c'
            // + MOD: Ensure the result of subtraction doesn't become negative before modulo
            long long added = (tot + 1 - ends[idx] + MOD) % MOD;
            
            // Update total distinct subsequences
            tot = (tot + added) % MOD;
            
            // Update the count of subsequences ending in this specific character
            ends[idx] = (ends[idx] + added) % MOD;
        }
        
        return static_cast<int>(tot);
    }
};