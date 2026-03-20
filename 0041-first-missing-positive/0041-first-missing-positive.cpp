class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        //hr element ko uski crrct index or swap kro
        for(int i=0;i<n;i++){
            //nums[i] ko tab tak swap kro jab tak
            //1)vo positive h 2)range [1...n]m h
            //3)aur uski crrct jagah(nums[i]-1)pe phle s shi value nhi bethi
            while(nums[i]>0&&nums[i]<=n&&nums[nums[i]-1]!=nums[i]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        //ab array m check kro kaunse index pr glt value h
        for(int i=0;i<n;i++){
            //agr posn i par i+1 nhi mila,to i+1 missng h
            if(nums[i]!=i+1){
                return i+1;
          }
        }
        //agr sb position match kr gye to nxt positive n+1 missing h
        return n+1;
    }
};
