class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left=0;
    int len=0;
    int res=0;
    int right;
    unordered_map<int,int>mp;
    for(int right=0;right<s.size();right++){
        mp[s[right]]++;
          while(mp[s[right]]>2){
          mp[s[left]]--;
              left++;
          }
      
          res=max(res,right-left+1);
    
    }
    return res;
    }
};