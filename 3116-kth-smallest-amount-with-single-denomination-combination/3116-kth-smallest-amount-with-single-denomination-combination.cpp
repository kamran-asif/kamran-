class Solution {
public:
long long gcdll(long long a,long long b){
    while(b){
        long long t=a%b;
        a=b;
        b=t;
    }
    return a;
}
long long lcmll(long long a,long long b){
    return a/gcdll(a,b)*b;
}
long long countnumbers(long long x,vector<int>&coins){
    int n=coins.size();
    long long count=0;
    for (int mask=1;mask<(1<<n);mask++){
        long long lcm=1;
        bool overflow=false;
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                lcm=lcmll(lcm,coins[i]);
                if(lcm>x){
                    overflow=true;
                    break;
                }
            }
        }
        if(overflow)
        continue;
        long long contrib=x/lcm;
        if(__builtin_popcount(mask)&1)
        count+=contrib;
        else
        count-=contrib;

    }
    return count;

}

    long long findKthSmallest(vector<int>& coins, int k) {
        long long low=1;
        long long high=1e18;
        long long ans=high;
    while(low<=high){
      long long mid=low+(high-low)/2;
      if(countnumbers(mid,coins)>=k){
        ans=mid;
        high=mid-1;

      }else{
        low=mid+1;
      }
    }
    return ans;
    }
};