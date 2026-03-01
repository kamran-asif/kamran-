class Solution {
public:
 //bottom up approach
  int climbStairs(int n) {
        if(n==1||n==2)
            return n;
        vector<int>dp(n+1,-1);
       //t[i] = total ways to climb i stairs
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++) {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
