class DSU {
public:
    vector<int> parent, rankv;

    DSU(int n) {
        parent.resize(n);
        rankv.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // path compression
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;

        if (rankv[a] < rankv[b]) swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b]) rankv[a]++;
        return true;
    }
};
class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
         DSU dsu(n);
        vector<bool> result;

        for (auto &req : requests) {
            int u = req[0], v = req[1];

            int pu = dsu.find(u);
            int pv = dsu.find(v);

            bool can = true;

            // Check every restriction
            for (auto &r : restrictions) {
                int x = r[0], y = r[1];

                int px = dsu.find(x);
                int py = dsu.find(y);

                // If merging u and v would put x and y in same group, reject
                if ((px == pu && py == pv) || (px == pv && py == pu)) {
                    can = false;
                    break;
                }
            }

            if (can) {
                dsu.unite(u, v);
            }

            result.push_back(can);
        }

        return result;
    }
};