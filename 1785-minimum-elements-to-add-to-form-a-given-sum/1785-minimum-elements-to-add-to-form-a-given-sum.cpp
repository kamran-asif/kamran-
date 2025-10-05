class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum=0;
        for(int x:nums)sum+=x;
        long long diff=goal-sum;
        if(diff<0)diff=-diff;
        long long ans=(diff+(long long)limit-1)/(long long)limit;
        return(int)ans;
    }
};