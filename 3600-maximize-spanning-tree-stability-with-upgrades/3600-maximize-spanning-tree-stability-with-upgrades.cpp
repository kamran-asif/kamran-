class Solution {
public:
struct DSU{
    vector<int>parent,sz;
    DSU(int n){
        parent.resize(n);
        sz.assign(n,1);
        iota(parent.begin(),parent.end(),0);

    }
    int find(int x){
       return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool unite(int a,int b){
        a=find(a),b=find(b);
         if(a==b)return false;
         if(sz[a]<sz[b])swap(a,b);
         parent[b]=a;
        sz[a]+=sz[b];
        return true;
    }
};
    int maxStability(int n, vector<vector<int>>& edges, int k) {
     int lo=1,hi=200000*2,ans=-1;
     auto can=[&](int mid)->bool{
        DSU dsu(n);
        int comps=n;
        int upgrades=0;
        int upgrades_used=0;
        for(auto &e:edges){
            int u=e[0],v=e[1],s=e[2],must=e[3];
            if(must==1){
                if(s<mid)return false;
                if(!dsu.unite(u,v))return false;
                comps--;
            }
        }
        vector<tuple<int,int,int>>normal,upgradable;
        for(auto&e:edges){
            int u=e[0],v=e[1],s=e[2],must=e[3];
            if(must==0){
                if(s>=mid){
                    normal.emplace_back(s,u,v);
                }else if(2ll*s>=mid){
                    upgradable.emplace_back(s,u,v);

                }
            }
        }
          sort(normal.begin(), normal.end(), greater<>());
      sort(upgradable.begin(), upgradable.end(), greater<>());
        for(auto&[s,u,v]:normal){
            dsu.unite(u,v);
        }
        for(auto&[s,u,v]:upgradable){
              if (upgrades<k&&dsu.unite(u,v)){
                upgrades++;
            }
        }
        int root=dsu.find(0);
        for(int i=0;i<n;i++){
            if(dsu.find(i)!=root)return false;
        }
        return true;
     }  ;
     while(lo<=hi){
      int mid=(lo+hi)/2;
      if(can(mid)){
        ans=mid;lo=mid+1;

      }else{
        hi=mid-1;
      }
     }
     return ans;
    }
};