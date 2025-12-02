class Solution {
public:
    double minTime(int n, int k, int m, vector<int>& time, vector<double>& mul) {
        const double INF = 1e18;
        const double EPS = 1e-9;

        if (k == 1 && n > 1) return -1.0;

        int fullMask = (1 << n) - 1;
        int totalStates = (1 << n) * m;

        vector<int> popc(1 << n, 0);
        vector<int> maxTime(1 << n, 0);
        for (int mask = 1; mask <= fullMask; ++mask) {
            popc[mask] = __builtin_popcount(mask);
            int mm = mask;
            int mx = 0;
            while (mm) {
                int b = __builtin_ctz(mm);
                mx = max(mx, time[b]);
                mm &= (mm - 1);
            }
            maxTime[mask] = mx;
        }

        auto idx = [&](int mask, int stage) {
            return mask * m + stage;
        };

        vector<double> dist((1 << n) * m, INF);
        using P = pair<double,int>;
        priority_queue<P, vector<P>, greater<P>> pq;

        int startMask = fullMask;
        dist[idx(startMask, 0)] = 0.0;
        pq.push({0.0, idx(startMask, 0)});

        double answer = -1.0;

        while (!pq.empty()) {
            auto [dcur, sidx] = pq.top(); pq.pop();
            if (dcur > dist[sidx] + 1e-12) continue; 
            int mask = sidx / m;
            int stage = sidx % m;

            if (mask == 0) { 
                answer = dcur;
                break;
            }

         
            for (int sub = mask; sub; sub = (sub - 1) & mask) {
                if (popc[sub] > k) continue;
                int mt = maxTime[sub];
                double cross = mt * mul[stage];
                long long flo = (long long)floor(cross + EPS);
                int s2 = (stage + (int)(flo % m)) % m;
                int new_mask = mask ^ sub; 

                if (new_mask == 0) {
                  
                    int ni = idx(0, s2);
                    double nd = dcur + cross;
                    if (nd + 1e-12 < dist[ni]) {
                        dist[ni] = nd;
                        pq.push({nd, ni});
                    }
                } else {
                    
                    int arrived = fullMask ^ new_mask; 
                    for (int rest = arrived; rest; rest &= (rest - 1)) {
                        int r = __builtin_ctz(rest);
                        double ret = time[r] * mul[s2];
                        long long flr = (long long)floor(ret + EPS);
                        int s3 = (s2 + (int)(flr % m)) % m;
                        int new_mask2 = new_mask | (1 << r); 
                        int ni = idx(new_mask2, s3);
                        double nd = dcur + cross + ret;
                        if (nd + 1e-12 < dist[ni]) {
                            dist[ni] = nd;
                            pq.push({nd, ni});
                        }
                    }
                }
            }
        }

        if (answer < -0.5) return -1.0;
        return answer;
    }
};
