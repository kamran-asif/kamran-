class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n=favorite.size();
        vector<int>indegree(n,0);
        for(int x:favorite)indegree[x]++;
        queue<int>q;
        vector<int>depth(n,1);
        vector<bool>removed(n,false);
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
            
        }while(!q.empty()){
            int u=q.front();q.pop();
            removed[u]=true;
            int v=favorite[u];
            depth[v]=max(depth[v],depth[u]+1);
            if(--indegree[v]==0)q.push(v);

        }
        int sumchain=0;
        for(int i=0;i<n;i++){
            int j=favorite[i];
            if(favorite[j]==i&&i<j){
                sumchain+=depth[i]+depth[j];

            }
        }
        int maxcycle=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!removed[i]&&!vis[i]){
                int curr=i,cnt=0;
                while(!vis[curr]){
                    vis[curr]=true;
                    curr=favorite[curr];
                    cnt++;

                }
           maxcycle=max(maxcycle,cnt);

            }
        
        }
        return max(maxcycle,sumchain);
    }
};