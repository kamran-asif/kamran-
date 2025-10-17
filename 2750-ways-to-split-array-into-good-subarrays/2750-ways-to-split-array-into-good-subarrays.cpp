class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        const long long MOD=1000000007LL;
        long long ans=1;
        int prev=-1;
        int cntones=0;
        for(int i=0;i<(int)nums.size();i++){
              if(nums[i]==1){
                if(prev!=-1){
                    ans=(ans*(long long)(i-prev))%MOD;
                }
                prev=i;
                ++cntones;
              }
        }
        if(cntones==0)return 0;
return (int)ans;
    }
};