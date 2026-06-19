class WordFilter {
public:
    unordered_map<string, int> mp;

    WordFilter(vector<string>& words) {
        for (int i = 0; i < (int)words.size(); i++) {
            const string& w = words[i];
            int n = w.size();

            for (int p = 0; p <= n; p++) {
                string pref = w.substr(0, p);
                for (int s = 0; s <= n; s++) {
                    string suff = w.substr(n - s);
                    mp[pref + "#" + suff] = i;
                }
            }
        }
    }

    int f(string pref, string suff) {
        string key = pref + "#" + suff;
        return mp.count(key) ? mp[key] : -1;
    }
};