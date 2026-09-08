class Solution {
public:
    void dfs(string word, string beginWord, unordered_map<string, int>& mpp, vector<string>& seq,
        vector<vector<string>>& ans){
            if (word == beginWord){
                reverse(seq.begin(), seq.end());
                ans.push_back(seq);
                reverse(seq.begin(), seq.end());
                return;
            }
            int val = mpp[word];
            for (int i = 0; i < word.size(); i++){
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if (mpp.find(word) != mpp.end() && mpp[word] == val-1){
                        seq.push_back(word);
                        dfs(word, beginWord, mpp, seq, ans);
                        seq.pop_back();
                    }
                }
                word[i] = original;
            }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        for (auto& it : wordList) words.insert(it);
        vector<vector<string>> ans;
        if (!words.count(endWord)) return ans;
        words.erase(beginWord);
        queue<string> q;
        unordered_map<string, int> mpp;
        int steps = 1;
        q.push({beginWord});
        mpp[beginWord] = 1;
        while (!q.empty()){
            string word = q.front();
            q.pop();
            steps = mpp[word];
            for (int i = 0; i < word.size(); i++){
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if (words.count(word)){
                        mpp[word] = steps+1;
                        q.push(word);
                        words.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        if (mpp.find(endWord) == mpp.end()) return ans;
        vector<string> seq = {endWord};
        dfs(endWord, beginWord, mpp, seq, ans);
        return ans;
    }
}; // BFS+DFS Approach :: T.C = O(N*M*26) & S.C = O(N^2*M)