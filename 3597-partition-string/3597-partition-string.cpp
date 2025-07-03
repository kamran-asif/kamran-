class Solution{
    public:


// Greedy segmentation with 64‑bit rolling hash
vector<string> partitionString(string s) {
    const uint64_t B = 131;  // base for rolling hash
    unordered_set<uint64_t> seen;
    seen.reserve(s.size());
    seen.max_load_factor(0.7);

    vector<string> ans;
    uint64_t cur_hash = 0;
    int start = 0;

    for (int i = 0, n = s.size(); i < n; ++i) {
        // extend rolling hash: h = h * B + (1-based char code)
        cur_hash = cur_hash * B + (uint64_t)(s[i] - 'a' + 1);

        // if this segment hash is new, emit it
        if (seen.find(cur_hash) == seen.end()) {
            ans.emplace_back(s.substr(start, i - start + 1));
            seen.insert(cur_hash);
            // reset for next segment
            cur_hash = 0;
            start = i + 1;
        }
    }
    return ans;
}
};