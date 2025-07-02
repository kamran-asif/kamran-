class Solution {
public:
    string reverseWords(string s) {
        int length=s.size();
        for(int start=0;start<length;start++){
            if(s[start] ==' ')continue;//skip the spaces
            int end=start;
            while(end<length&&s[end] != ' '){
              end++;
             
              
            }
             reverse(s.begin()+start,s.begin()+end);
             start=end;

        }
        return s;
    }
};