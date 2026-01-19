class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        
        // cnt[j] will store the number of pairs (i, k) such that 
        // i < j < k and nums[i] < nums[k] < nums[j]
        vector<long long> cnt(n, 0);

        for (int j = 0; j < n; ++j) {
            int prev_smaller = 0;
            for (int i = 0; i < j; ++i) {
                if (nums[i] < nums[j]) {
                    // This (i, j) can serve as (a, d) for any existing (b, c) pairs
                    count += cnt[i];
                    prev_smaller++;
                } else if (nums[i] > nums[j]) {
                    // If nums[i] > nums[j], then (i, j) can be a (b, c) pair.
                    // We add the number of 'a's found so far (prev_smaller) to cnt[i].
                    cnt[i] += prev_smaller;
                }
            }
        }
        return count;
    }
};