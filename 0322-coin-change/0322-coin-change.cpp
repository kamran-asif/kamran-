class Solution {
public:
//revisit
// amount type prblmn h to like sum-smthng=0 hona chaye
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=0;i<=amount;i++){
            for(auto c:coins){
                if(i-c>=0){
                    dp[i]=min(dp[i],1+dp[i-c]);
             }

                }            }
            return (dp[amount]==amount+1)?-1:dp[amount];
        }
    
};
