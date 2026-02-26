class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=0;
        int idx=-1;
        int end=nums.size()-1;
        int mid=end+(start-end)/2;
        while(start<=end){
              if(mid<target){
                start=mid+1;

              }else if(mid==target)
              {
                idx=mid;
              }else{
                end=mid-1;
              }
        }
   return idx; 
    }

};
