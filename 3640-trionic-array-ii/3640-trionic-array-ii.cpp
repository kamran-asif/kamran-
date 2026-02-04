class Solution {
public:
    using ll = long long;
    static const ll NEG_INF = LLONG_MIN / 4;

    struct Node {
        ll total;
        ll suf;
        ll pref;
        Node() : total(0), suf(NEG_INF), pref(NEG_INF) {}
        Node(ll total_, ll suf_, ll pref_) : total(total_), suf(suf_), pref(pref_) {}
    };

    class SegmentTree {
    public:
        vector<Node> tree;
        int n;
        SegmentTree(int n, const vector<int>& arr) {
            this->n = n;

            tree.assign(4 * n, Node());
            init(0, 0, n - 1, arr);
        }

        Node merge(const Node& a, const Node& b) {
            if (a.suf == NEG_INF)
                return b;
            if (b.suf == NEG_INF)
                return a;

            Node res;
            res.total = a.total + b.total;
            res.suf = max(b.suf, b.total + a.suf);
            res.pref = max(a.pref, a.total + b.pref);
            return res;
        }

        void init(int node, int l, int r, const vector<int>& arr) {
            if (l == r) {
                ll v = arr[l];
                tree[node] = Node(v, v, v);
                return;
            }
            int mid = (l + r) / 2;
            init(node * 2 + 1, l, mid, arr);
            init(node * 2 + 2, mid + 1, r, arr);

            tree[node] = merge(tree[node * 2 + 1], tree[node * 2 + 2]);
        }

        Node query(int node, int l, int r, int ql, int qr) {
            if (qr < l || r < ql)
                return Node();
            if (ql <= l && r <= qr)
                return tree[node];

            int mid = (l + r) / 2;
            return merge(query(node * 2 + 1, l, mid, ql, qr),
                         query(node * 2 + 2, mid + 1, r, ql, qr));
        }

        ll max_suffix(int l, int r) {
            Node res = query(0, 0, n - 1, l, r);
            return res.suf;
        }
        ll max_prefix(int l, int r) {
            Node res = query(0, 0, n - 1, l, r);
            return res.pref;
        }
    };
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        ll maxv = LLONG_MIN;

        vector<int> prefix(n, 0), suffix(n, 0);
        prefix[0] = suffix[n - 1] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                prefix[i] = prefix[i - 1] + 1;
            } else {
                prefix[i] = 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                suffix[i] = suffix[i + 1] + 1;
            } else {
                suffix[i] = 1;
            }
        }

        SegmentTree seg(n, nums);

        for (int i = 1; i + 1 < n;) {
            if (nums[i] > nums[i + 1]) {
                int p = i;
                ll sum = nums[i];

                while (i + 1 < n && nums[i] > nums[i + 1]) {
                    sum += nums[i + 1];
                    i++;
                }

                int q = i;

                if (p >= 1 && q + 1 < n) {
                    int len1 = prefix[p];
                    int len2 = suffix[q];
                    
                    if (len1 >= 2 && len2 >= 2) {
                        int L = p - len1 + 1; 
                        int Rl = p - 1;
                        int Rr = q + len2 - 1; 

                        ll left_part = seg.max_suffix(L, Rl);
                        ll right_part = seg.max_prefix(q + 1, Rr);

                        if (left_part != NEG_INF && right_part != NEG_INF) {
                            ll cand = left_part + sum + right_part;
                            maxv = max(maxv, cand);
                        }
                    }
                }
            } else {
                i++;
            }
        }

        return maxv;
    }
};