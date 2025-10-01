class Solution {
public:

long long maximumScore(vector<int>&scores,vector<vector<int>>& edges){
        int n=scores.size();
        vector<vector<int>>bestneighbors(n);
        vector<vector<int>>adj(n);

        for (auto &e:edges){
            int u=e[0],v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        
        for (int i=0;i<n;i++){
            sort(adj[i].begin(),adj[i].end(),[&](int a,int b){
                return scores[a]>scores[b];
            });
            for (int j=0;j<min(3,(int)adj[i].size());j++){
                bestneighbors[i].push_back(adj[i][j]);
            }
        }

        long long ans=-1;

        
        for (auto &e:edges){
            int u=e[0],v=e[1];
            for (int a:bestneighbors[u]){
                if (a==v) continue;
                for (int b:bestneighbors[v]){
                    if (b==u||b==a) continue;
                    long long score=(long long)scores[a]+scores[u]+scores[v]+scores[b];
                    ans=max(ans,score);
                }
            }
        }

        return ans;
    
    }
};