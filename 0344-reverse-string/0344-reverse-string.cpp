class Solution {
public:
    void reverseString(vector<char>& s) {
     int i=0;
     int n=s.size();
     for(int j=n-1;j>i;j--){
        swap(s[i],s[j]);
     i++;
     }
      
    }
};