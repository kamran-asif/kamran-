class NumMatrix {
public:
    vector<vector<long long>> ps;

    NumMatrix(vector<vector<int>>& matrix) {
       int m = matrix.size();
       if (m == 0) return;
       int n = matrix[0].size();
       ps.assign(m + 1, vector<long long>(n + 1, 0));
       for (int i = 0; i < m; i++) {
           for (int j = 0; j < n; j++) {
               ps[i+1][j+1] = matrix[i][j] + ps[i][j+1] + ps[i+1][j] - ps[i][j];
           }
       }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (ps.empty()) return 0;
        long long res = ps[row2+1][col2+1]
                      - ps[row1][col2+1]
                      - ps[row2+1][col1]
                      + ps[row1][col1];
        return static_cast<int>(res);   
    }
};
