class Solution {
public:
vector<int>toposort(int k,const vector<vector<int>>&conds){
    vector<vector<int>>adj(k);
    vector<int>indeg(k,0);
    vector<unordered_set<int>>seen(k);
    for(auto&e:conds){
        int u=e[0]-1;
        int v=e[1]-1;
        if(u==v)continue;
        if(!seen[u].count(v)){
            seen[u].insert(v);
            adj[u].push_back(v);
            indeg[v]++;
        }
    }
        queue<int>q;
        for(int i=0;i<k;i++)if(indeg[i]==0)q.push(i);
        vector<int>order;
        while(!q.empty()){
            int u=q.front();q.pop();
            order.push_back(u);
            for(int v:adj[u]){
                if(--indeg[v]==0)q.push(v);

            }
        }
        if((int)order.size()!=k) return {};
        return order;
}
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>roworder=toposort(k,rowConditions);
        if(roworder.empty())return{};
        vector<int>colorder=toposort(k,colConditions);
        if(colorder.empty())return{};
        vector<int>rowpos(k),colpos(k);
       
            for(int i=0;i<k;i++)rowpos[roworder[i]]=i;
            for(int i=0;i<k;i++)colpos[colorder[i]]=i; 
            vector<vector<int>>mat(k,vector<int>(k,0));
            for(int num=0;num<k;num++){
                int r=rowpos[num];
                int c=colpos[num];
                mat[r][c]=num+1;
            }
        
      return mat;
        }
       
};
