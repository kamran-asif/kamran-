class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
     vector<vector<pair<int,double>>>adj(n);
     for(int i=0;i<edges.size();i++){
        int u=edges[i][0],v=edges[i][1];
        double prob=succProb[i];
        adj[u].push_back({v,prob});
        adj[v].push_back({u,prob});

     }
     priority_queue<pair<double,int>>pq;
     vector<double>maxprob(n,0.0);
     maxprob[start]=1.0;
     pq.push({1.0,start});
     while(!pq.empty()){
        auto[prob,node]=pq.top();
        pq.pop();
        if(node==end)return prob;
        for(auto[nbr,edgeprob]:adj[node])
     }

    }
};