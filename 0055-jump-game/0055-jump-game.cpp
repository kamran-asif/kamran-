class Solution {
public:
    bool canJump(vector<int>& nums) {
        int left=0;
       
        for(int i=0;i<nums.size();i++){
            if(i>left)
            return false;
            left=max(left,i+nums[i]);
        }
        return true;
    }
};