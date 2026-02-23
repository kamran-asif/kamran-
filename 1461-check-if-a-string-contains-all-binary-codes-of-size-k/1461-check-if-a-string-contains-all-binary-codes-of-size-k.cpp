class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        
        if (n < k) return false;
        
        int total = 1 << k;
        if (n - k + 1 < total) return false;
        
        vector<bool> seen(total, false);
        
        int mask = total - 1;
        int curr = 0;
        int count = 0;
        
        for (int i = 0; i < k; i++) {
            curr = (curr << 1) | (s[i] - '0');
        }
        
        if (!seen[curr]) {
            seen[curr] = true;
            count++;
        }
        
        for (int i = k; i < n; i++) {
            curr = ((curr << 1) & mask) | (s[i] - '0');
            
            if (!seen[curr]) {
                seen[curr] = true;
                count++;
                if (count == total) return true;
            }
        }
        
        return count == total;
    }
};