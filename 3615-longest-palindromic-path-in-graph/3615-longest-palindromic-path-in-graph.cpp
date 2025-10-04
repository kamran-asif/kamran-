class Solution{
    public:
int maxLen(int n, vector<vector<int>>& edges, string label){
    vector<vector<int>>adj(n);
    for (auto &e:edges){
        int u=e[0],v=e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
         int maxmsk=1<<n;
    long long ttlsts=(long long)maxmsk*n*n;
 vector<char>visited((size_t)ttlsts,0);
    auto idx=[&](int msk,int l,int r)->size_t{
        return (size_t)msk*n*n+(size_t)l*n+(size_t)r;
    };
    int ans=1;
    deque<tuple<int,int,int>>dq;
    for (int c=0;c<n;++c){
        int msk=1<<c;
        size_t id=idx(msk,c,c);
        if (!visited[id]){
            visited[id]=1;
            dq.emplace_back(msk,c,c);
            ans=max(ans,1);
        }
    }
    for (int u=0;u<n;++u){
        for (int v:adj[u]){
            if (u<v&&label[u]==label[v]){
                int msk=(1<<u)|(1<<v);
                size_t id1=idx(msk,u,v);
                if (!visited[id1]){
                    visited[id1]=1;
                    dq.emplace_back(msk,u,v);
                    ans=max(ans,2);
                }
                size_t id2=idx(msk,v,u);
                if (!visited[id2]){
                    visited[id2]=1;
                    dq.emplace_back(msk,v,u);
                }
            }
        }
    }
    while (!dq.empty()){
        auto [msk,l,r]=dq.front();
        dq.pop_front();
        ans = max(ans,__builtin_popcount((unsigned)msk));
        for (int nl:adj[l]) {
            if (msk&(1<<nl))continue; 
            for (int nr:adj[r]){
        if (msk&(1<<nr))continue; 
         if (nl==nr)continue;
        if (label[nl]!=label[nr])continue;
         int nmsk=msk|(1<<nl)|(1<<nr);
           size_t idn=idx(nmsk,nl,nr);
           if (!visited[idn]){
           visited[idn]=1;
                dq.emplace_back(nmsk,nl,nr);
                }
            }
        }
    }

    return ans;
}

};
