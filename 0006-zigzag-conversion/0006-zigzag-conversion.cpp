class Solution {
public:
//google
    string convert(string s, int numRows) {
       if(s.empty())return "";
       if(numRows<=1)return s;
       int k=0,increment=1;
       vector<string>strs(numRows);
       int n=s.size();
       for(int i=0;i<s.size();i++){
        strs[k].push_back(s[i]);
        if(k==numRows-1){
            increment=-1;

        }else if(k==0){
            increment=1;
        }
        k+=increment;
       }
string ret;
for(auto&s:strs)ret+=s;
return ret;
    }

};
