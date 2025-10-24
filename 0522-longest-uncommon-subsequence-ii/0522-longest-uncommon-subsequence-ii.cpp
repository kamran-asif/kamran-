class Solution {
public:
    bool issubsequences(const string &large,const string &small){
        int i=0,j=0;
        int n=large.size(),m=small.size();
        while (i<n&&j<m){
               if (large[i]==small[j])++j;
                ++i;
 }
        return j==m;
 }

    int findLUSlength(vector<string>&strs){
        int n=strs.size();
        int ans=-1;
         for (int i=0;i<n;i++){
         bool uncommon=true;
             for (int j=0;j<n;++j){
                if (i==j)continue;
                if (issubsequences(strs[j],strs[i])){
                      uncommon=false;
                       break;
     }
   }
                if(uncommon)ans=max(ans,(int)strs[i].size());
}

        return ans;
    }
};
