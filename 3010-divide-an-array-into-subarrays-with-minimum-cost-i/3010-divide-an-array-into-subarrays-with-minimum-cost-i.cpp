class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int c1=nums[0];
        int c2=nums[1];
        int c3=nums[2];

        for(int i=3;i<nums.size();i++){
            if(nums[i]<c2){
                int temp = c3;
                c3 = nums[i];
                if(temp<c2) c2=temp;
            }else if(nums[i]<c3){
                c3 = nums[i];
            }
        }

        int ans=c1+c2+c3;

        return ans;
    }
};