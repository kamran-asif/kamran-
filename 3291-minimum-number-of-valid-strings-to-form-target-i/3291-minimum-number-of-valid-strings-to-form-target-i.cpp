class Solution {
public:
   vector<int> prefix_function(const string &s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}    
int minValidStrings(vector<string>& words, string target) {
    vector<vector<int>> pis;
    for (const auto &w : words)
        pis.push_back(prefix_function(w + "#" + target));
    int len = target.size(), res = 0;
    while(len > 0) {
        int match = 0;
        for (int i = 0; i < words.size(); ++i)
            match = max(match, pis[i][words[i].size() + len]);
        if (match == 0)
            return -1;
        ++res;
        len -= match;
    }
    return res;
}
};