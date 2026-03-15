class Solution {
public:
    vector<int> findOrder(int numCourses,vector<vector<int>>& prerequisites) {
        //list ko represnt krte hai aise
        vector<int>adj[numCourses];
        for (auto it:prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
//in degree array
        vector<int> indegree(numCourses,0);
        for (int i=0;i<numCourses;i++) {
            for (auto it:adj[i]) {
                indegree[it]++;
           }
        }
// queue use kr rhe hai indegree store krne k liy 
        queue<int> q;
        for (int i=0;i<numCourses;i++) {
            if (indegree[i]==0) {
                q.push(i);
            }
        }
//khan's algo 
        vector<int> topo;
        while (!q.empty()) {
            int node=q.front();
            q.pop();
            topo.push_back(node);

            for (auto it:adj[node]) {
                indegree[it]--;
                if (indegree[it]==0) {
                    q.push(it);
                }
            }
        }
// agr topo sort me sare courses hai to return krdo wrna empty retrn kro
        if (topo.size()==numCourses)return topo;
        return {};
    }
};
