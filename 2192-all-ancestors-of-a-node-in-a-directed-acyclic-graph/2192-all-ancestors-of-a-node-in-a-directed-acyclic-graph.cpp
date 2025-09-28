class Solution {
public:
    vector<vector<int>> getAncestors(int n,vector<vector<int>>& edges) {
        vector<vector<int>>revgraph(n);
        for (auto &e:edges){
            int from=e[0],to=e[1];
            revgraph[to].push_back(from);
        }
        vector<vector<int>>result(n);
        for (int i=0;i<n;i++){
            vector<bool>visited(n,false);
            dfs(i,revgraph,visited,result[i]);
            sort(result[i].begin(),result[i].end());
        }

        return result;
    }

private:
    void dfs(int node,vector<vector<int>>& revgraph, vector<bool>& visited,vector<int>& ancestors){
        for (int parent:revgraph[node]){
            if (!visited[parent]){
                visited[parent]=true;
                ancestors.push_back(parent);
                dfs(parent,revgraph,visited,ancestors);
            }
        }
    }
};
