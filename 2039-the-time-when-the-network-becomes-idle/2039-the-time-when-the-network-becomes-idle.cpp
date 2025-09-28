class Solution {
public: // kafi acha sval h
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience){
        int n=patience.size();
        vector<vector<int>>graph(n);
        //kch na adjncy lst bna re bs
        for (auto &e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

//jst usng bfs
        vector<int>dist(n,-1);
        queue<int>q;
        dist[0]=0; 
        q.push(0);

        while (!q.empty()){
            int u=q.front();
            q.pop();
            for (int v:graph[u]){
                if (dist[v]==-1){ 
                    dist[v]=dist[u]+1;
                    q.push(v);
                }
            }
        }

        // ntwrk idle k tme clclte krte h
        long long ans=0;
        for (int i=1;i<n;i++){ 
            int rt=dist[i]*2; 

            // lst scnd srvr i ne msg bhja befre rply aya
            int lstsnd=((rt-1)/patience[i])*patience[i]
             
            long long lstarrival=(long long)lstsnd+rt; // lst msg k rply srvr i pr ane k time

            ans=max(ans,lstarrival); 
        }

        return ans+1; 
    }
};
