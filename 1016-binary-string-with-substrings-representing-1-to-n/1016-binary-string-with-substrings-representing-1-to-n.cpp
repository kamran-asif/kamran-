class Solution {
public:
    bool queryString(string s, int n){
        int m =s.size();
        int L=32-__builtin_clz((unsigned)n);
        L=min(L,30);
        unordered_set<int>seen;
        seen.reserve(1024);
       for (int len=1;len<=L;++len){
        if (len>m) break;
        int mask=(1<<len)-1;         
        int val=0;
        for (int i=0;i<m;++i){
            val=((val<<1)&mask)|(s[i]-'0');
            if (i>=len-1){
                int start=i-(len-1);
                if (s[start]=='1'){
                    if (val>=1&&val<=n){
                        seen.insert(val);
                        if ((int)seen.size()==n) return true; 
        }
                }
            }
                
        }
       }
       return (int) seen.size()==n;
    }
       
        
            
};