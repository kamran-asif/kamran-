class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto&e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back({v,0});
            adj[v].push_back({u,1});
        }
        vector<int>ans(n,0);
        function<int(int,int)>dfs1=[&](int node,int parent){
            int reversal=0;
            for(auto&[nbr,cost]:adj[node]){
                if(nbr==parent)
                continue;
                reversal+=cost;
                reversal+=dfs1(nbr,node);
            }
            return reversal;
        };
        ans[0]=dfs1(0,-1);
        function<void(int,int)>dfs2=[&](int node,int parent){
            for(auto&[nbr,cost]:adj[node]){
                if(nbr==parent)
                continue;
            
            if(cost==0)
            ans[nbr]=ans[node]+1;
            else 
            ans[nbr]=ans[node]-1;
            dfs2(nbr,node);
        }
    };
    dfs2(0,-1);
    return ans;
    }
};