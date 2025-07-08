#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        // Sort events by start time
        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            return a[0] < b[0];
        });
        n = events.size();
        this->k = k;
        this->events = &events;

        // Initialize dp with -1 indicating uncomputed states
        dp.assign(k + 1, vector<long long>(n, -1));

        return (int)dfs(0, k);
    }

private:
    int n;
    int k;
    vector<vector<int>>* events;
    vector<vector<long long>> dp;

    long long dfs(int curIndex, int count) {
        // Base case: no picks left or no events remaining
        if (count == 0 || curIndex == n) {
            return 0;
        }
        if (dp[count][curIndex] != -1) {
            return dp[count][curIndex];
        }

        // Option 1: skip current event
        long long skip = dfs(curIndex + 1, count);

        // Option 2: take current event
        int nextIndex = findNext(curIndex);
        long long take = (*events)[curIndex][2] + dfs(nextIndex, count - 1);

        // Memoize and return
        return dp[count][curIndex] = max(skip, take);
    }

    // Find the first event whose start time is greater than the end time of events[curIndex]
    int findNext(int curIndex) {
        int target = (*events)[curIndex][1];
        int low = curIndex + 1, high = n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if ((*events)[mid][0] <= target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};
