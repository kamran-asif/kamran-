class Solution {
public:bool isTrionic(vector<int> &nums) {
    int n = nums.size();
    if (n < 4) return false;

    if (nums[1] <= nums[0]) return false;

    bool vis[205][3] = {};
    queue<pair<int,int>> q;

    q.push({1,0});
    vis[1][0] = true;

    while (!q.empty()) {
        auto [i,p] = q.front();
        q.pop();

        if (i == n-1 && p == 2) return true;

        if (i+1 >= n) continue;

        int d = nums[i+1] - nums[i];
        if (d == 0) continue;

        if (d > 0) {
            if (p == 0 || p == 2) {
                if (!vis[i+1][p]) {
                    vis[i+1][p] = true;
                    q.push({i+1,p});
                }
            }
            if (p == 1) {
                if (!vis[i+1][2]) {
                    vis[i+1][2] = true;
                    q.push({i+1,2});
                }
            }
        } else {
            if (p == 0 || p == 1) {
                if (!vis[i+1][1]) {
                    vis[i+1][1] = true;
                    q.push({i+1,1});
                }
            }
        }
    }

    return false;
}
};