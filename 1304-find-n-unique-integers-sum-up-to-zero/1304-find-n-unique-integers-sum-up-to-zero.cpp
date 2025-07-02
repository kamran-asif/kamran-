class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>result(n);
        for(int i=0;i<result.size();i++){
            result[i]=i+1;
        }
        result[n-1]=-(n-1)*n/2;
        return result;
    }
};