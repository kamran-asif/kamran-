
class Solution{
public:
int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
 int minDiff = nums[k-1] - nums[0];
        
        for (int i = 1; i <= nums.size() - k; i++) {
            int currentDiff = nums[i + k - 1] - nums[i];
            minDiff = min(minDiff, currentDiff);
        }
        
        return minDiff;
    }
};
