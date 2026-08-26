class Solution {
public:
    int lengthLongestPath(string input) {
        stringstream ss(input);
        string line;

        unordered_map<int, int> d;
        d[0] = 0;

        int ans = 0;

        while (getline(ss, line, '\n')) {

            int level = 0;

            // Count tabs
            while (level < line.size() && line[level] == '\t') {
                level++;
            }

            // File name ki length
            int len = line.size() - level;

            // File hai
            if (line.find('.', level) != string::npos) {
                ans = max(ans, d[level] + len);
            }

            // Directory hai
            else {
                d[level + 1] = d[level] + len + 1;
            }
        }

        return ans;
    }
};