class Solution {
public:
    string reverseWords(string s) {
      vector<string>words;
      int n=s.size();
      //string ko parse karke words nikalo
      for(int i=0;i<n;i++){
//skip cases
while(i<n&&s[i]==' ')i++;
if(i>=n)break;
int j=i;
//word ki boundary find kro
while(j<n&&s[j]!=' ')j++;
//substring from i to j-1 ek word
words.push_back(s.substr(i,j-i));
i=j; 
      }
      //ab reverse order m words ko join krenge
      string res;
      for(int k=(int)words.size()-1;k>=0;k--){
        res += words[k];
        if(k>0)res+=' ';//beech m single space add kro
      }
      return res;
          }
};