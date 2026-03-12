class Solution {
public:
 vector<vector<int>> permuteUnique(vector<int>& nums) {
        
//khandani template
vector<vector<int>>result;
unordered_set<int>st;
void solve(vector<int>& nums, vector<int>&temp){
    int  n=nums.size();
   
       if(temp.size()==n){
        result.push_back(temp);
        return;
       }
       for(int i=0;i<n;i++){
        if(st.find(nums[i])==st.end()){
           temp.push_back(nums[i]);
           st.insert(nums[i]);
           solve(nums,temp);
           temp.pop_back();
          st.erase(nums[i]);
        }
     }
}
    vector<vector<int>> permute(vector<int>& nums) {
 int  n=nums.size();
      vector<int>temp;
solve(nums,temp);
return result;

    }
};
   
