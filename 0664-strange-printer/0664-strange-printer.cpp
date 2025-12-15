class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n,INT_MAX));
        for (int i=n-1;i>=0;i--){
            dp[i][i]=1;// ek sngle chr ko prnt krne m 1 turn lgta h
            
            for (int j=i+1;j<n;j++){
                if (s[i]==s[j]){
                    // bs end wale ko ignre kr prvious sbstrng k cst le lo
                  dp[i][j]=dp[i][j-1];
                }else{
                   //dfferent chr h toh hr pssble split point try kro
                for (int k=i;k<j;++k){
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                    }
                }
            }
        }
        return dp[0][n -1];
    }
};
