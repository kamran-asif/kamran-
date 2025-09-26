class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                          vector<vector<int>>& friends, int id,
                                          int level){
        int n=friends.size();
        vector<int>visited(n,0);
        queue<int>q;
        q.push(id);
        visited[id]=1;
        int currlvl=0;
        while (!q.empty()&&currlvl<level) {
            int size=q.size();
            while (size--){
                int person=q.front();
                q.pop();
                for (int f:friends[person]){
                    if (!visited[f]){
                        visited[f]=1;
                        q.push(f);
                    }
                }
            }
            currlvl++;
        }
        unordered_map<string,int>freq;
        while(!q.empty()){
            int person=q.front();
            q.pop();
            for (string&video:watchedVideos[person]){
                freq[video]++;
            }
        }
        vector<pair<string,int>>vec(freq.begin(), freq.end());
        sort(vec.begin(),vec.end(),[](auto& a, auto& b){
            if(a.second==b.second)
                return a.first<b.first;
            return a.second<b.second;
        });
        vector<string>result;
        for (auto& p:vec)
            result.push_back(p.first);
        return result;
    }
};
