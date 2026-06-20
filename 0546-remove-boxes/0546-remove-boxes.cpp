class Solution {
public:// dp with graph
    int removeBoxes(vector<int>& boxes) {
        int n = (int)boxes.size();
        // memo[l][r][k] = answer, -1 means not computed
        memo.assign(n, vector<vector<int>>(n, vector<int>(n, -1)));
        this->boxes = boxes;
        return dfs(0, n - 1, 0);
    }
private:
    vector<int> boxes;
    vector<vector<vector<int>>> memo;

    int dfs(int l, int r, int k) {
        // agar segment khali ho gaya
        if (l > r) return 0;

        int &res = memo[l][r][k];
        if (res != -1) return res;

        // Right se same color ke continuous boxes ko compress karo
        // taaki states kam ho jayein.
        while (l < r && boxes[r] == boxes[r - 1]) {
            --r;
            ++k;            // ek aur same color box add ho gaya
        }

        // Option A: abhi ke abhi ye (k+1) boxes hata do
        res = dfs(l, r - 1, 0) + (k + 1) * (k + 1);

        // Option B: kisi pehle wale boxes[i] (same color) ke saath merge karo
        for (int i = l; i < r; ++i) {
            if (boxes[i] == boxes[r]) {
                // Middle part (i+1..r-1) ko pehle hata do,
                // phir boxes[i] aur boxes[r] ek block ban jayenge.
                res = max(res,
                          dfs(l, i, k + 1) +   // ab boxes[i] ke saath k+1 same-color boxes
                          dfs(i + 1, r - 1, 0));
            }
        }

        return res;
    }
};
   
   