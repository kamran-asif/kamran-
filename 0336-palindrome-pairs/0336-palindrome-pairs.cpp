class Solution {
public:
    //check if string from left to right is palindrome
    bool ispalindrome(const string& str, int left, int right) {
        while (left < right) {
            if (str[left++] != str[right--]) return false;
        }
        return true;    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        unordered_map<string, int> reversemap;
        //har word ka reverse banake map mein store karo
        for (int i = 0; i < words.size(); i++) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            reversemap[rev] = i;
        }

        //har word ke liye har split point check karo
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];

            // 0 se word.size() tak (<=) because we check both left and right
            for (int j = 0; j <= word.size(); j++) {
                string left = word.substr(0, j);
                string right = word.substr(j);

                // agar left part palindrome hai, to check karo ki right ka reverse kisi aur word mein hai ya nahi
                if (ispalindrome(word, 0, j - 1)) {
                    if (reversemap.count(right) && reversemap[right] != i) {
                        result.push_back({reversemap[right], i});
                    }
                }

                // agar right part palindrome hai, aur j != word.size() (to avoid duplicate)
                if (j != word.size() && ispalindrome(word, j, word.size() - 1)) {
                    if (reversemap.count(left) && reversemap[left] != i) {
                        result.push_back({i, reversemap[left]});
                    }
                }
            }
        }

        return result;
    }
};
