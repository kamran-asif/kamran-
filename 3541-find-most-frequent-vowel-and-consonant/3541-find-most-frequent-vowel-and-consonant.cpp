class Solution {
public:
bool is(char c){
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
    int maxFreqSum(string s){
      unordered_map<char,int>mp;
      for(auto ch:s){
        mp[ch]++;
      }
      int vowel=0,consonent=0;
      for(char ch='a';ch<='z';ch++){
        if(is(ch)){
            vowel=max(vowel,mp[ch]);
        }else{
            consonent=max(consonent,mp[ch]);
        }
        
      }
    return vowel+consonent;
    }     
    
};