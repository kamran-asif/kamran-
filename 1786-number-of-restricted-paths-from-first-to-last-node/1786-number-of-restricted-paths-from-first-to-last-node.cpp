class Solution {
public:
//tough hrd one revisit
    const int MOD=1e9+7;
    vector<vector<pair<int,int>>>graph;
    vector<long long>dist;
    vector<int>memo;//
//path u s n tk
    int dfs(int u){
        //base case agr node n pr h to srf exctly 1 hi path h
        if (u==(int)graph.size()-1) return 1;
        if (memo[u]!=-1) return memo[u];

        long long ways=0;
        //explore neighbrs kro
        for (auto [v,w]:graph[u]){
            if (dist[u]>dist[v]){ 
                ways+=dfs(v);
                ways%=MOD;
            }
        }
        return memo[u]=(int)ways;
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges){
        graph.assign(n+1,{});
        for (auto &e:edges){
            int u=e[0],v=e[1],w=e[2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
    //djisktra run kro frm node n s 
        dist.assign(n+1,LLONG_MAX);
        dist[n]=0;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq;
        pq.push({0,n});

        while(!pq.empty()){
            auto [d,u]=pq.top();//smmlst ko get krne k liy
            pq.pop();
            if (d>dist[u])continue;
            for (auto [v,w]:graph[u]){
                if (dist[v]>d+w){
                    dist[v]=d+w;
                    pq.push({dist[v],v});
                }
            }
        }

        memo.assign(n+1,-1);
        return dfs(1);
    }
};
