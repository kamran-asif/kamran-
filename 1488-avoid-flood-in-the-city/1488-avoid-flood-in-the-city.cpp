class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        vector<int>ans(n,1);
        unordered_map<int,int>last;
        set<int>drydays;
        for(int i=0;i<n;i++){
            if(rains[i]>0){
            int lake=rains[i];
            ans[i]=-1;
            if(last.find(lake)!=last.end()){
                int prevday=last[lake];
                auto it=drydays.upper_bound(prevday);
                if(it==drydays.end()){
                        return {};
                    }
                    ans[*it]=lake;
                    drydays.erase(it);
                }
                last[lake]=i;
            }else{
                drydays.insert(i);
            }
            }
        
        return ans;
    }
};