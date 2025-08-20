class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos,
                vector<int>& rowCosts, vector<int>& colCosts) {
        long long cost = 0;                 // use long long for safety
        int sr = startPos[0], sc = startPos[1];
        int hr = homePos[0],  hc = homePos[1];

        int step = (hr > sr) ? 1 : -1;      // move along rows
        for (int r = sr + step; r != hr + step; r += step) {
            cost += rowCosts[r];
        }

        step = (hc > sc) ? 1 : -1;          // move along columns
        for (int c = sc + step; c != hc + step; c += step) {
            cost += colCosts[c];
        }

        return static_cast<int>(cost);
    }
};
