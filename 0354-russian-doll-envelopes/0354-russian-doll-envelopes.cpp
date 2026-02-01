class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // handle empty input case
        if (envelopes.empty()) return 0;

        //sort envelopes using custom comparator
        // width (w1) ascending, height (w2) descending when widths equal
        sort(envelopes.begin(), envelopes.end(),
            [](const vector<int>& a, const vector<int>& b) {
                // if widths are equal, sort by height in descending order (lrger height first)
                if (a[0] == b[0])
                    return a[1] > b[1]; // height descending if width same
                // otherwise sort by width in ascending order (smaller width first)
                return a[0] < b[0];     // width ascending
            });

        //use LIS on heights only
        // this vector will store the smallest possible tail for each length of chain
        vector<int> lis;
        
        // iterate through each sorted envelope
        for (auto &env : envelopes) {
            //extract height (second element) from current envelope
            int h = env[1];
            
            // find first position in lis where value >= h (using binary search)
            auto it = lower_bound(lis.begin(), lis.end(), h);
            
            // if no such position found (h is larger than all in lis), extend the chain
            if (it == lis.end())
                lis.push_back(h);  // append h to extend longest chain
            // otherwise, replace the element at this position with h
            // this keeps smallest possible tail for this chain length
            else
                *it = h;           //replace with smaller height for better future matches
        }

      
        return lis.size();
    }
};
