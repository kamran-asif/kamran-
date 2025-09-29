class Solution {
public: 
    int minSubarray(vector<int>& nums, int p) {
      long long ttlsum=0;
      for(int x:nums)ttlsum+=x;
      int remainder=ttlsum%p;
      if(remainder==0)return 0;
      unordered_map<int,int>lstindex;
      lstindex[0]=-1; 
      long long prefix=0;
      int res=nums.size();
      for(int i=0;i<nums.size();i++){
        prefix=(prefix+nums[i])%p;
        int trgt=(prefix-remainder+p)%p;
        if(lstindex.count(trgt)){
            res=min(res,i-lstindex[trgt]);
        }
        lstindex[prefix]=i;
      }
      return (res==nums.size())?-1:res;  
    }  
};