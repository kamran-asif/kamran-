class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxsum = INT_MIN;

        for (int left = 0; left < cols; left++) {
            vector<int> temp(rows, 0);

            for (int right = left; right < cols; right++) {
                for (int i = 0; i < rows; i++) {
                    temp[i] += matrix[i][right];
                }

                set<int> prefixsums = {0};
                int prefix = 0;
                int localmax = INT_MIN;

                for (int i = 0; i < rows; i++) {
                    prefix += temp[i];

                    auto it = prefixsums.lower_bound(prefix - k);
                    if (it != prefixsums.end()) {
                        localmax = max(localmax, prefix - *it);
                    }

                    prefixsums.insert(prefix);
                }

                maxsum = max(maxsum, localmax);
            }
        }
        return maxsum;
    }
};
