
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> firstIndex;
        firstIndex.reserve(nums.size()*2);
        firstIndex[0] = -1; 
        int maxLen = 0;
        int prefix = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
          
            prefix += (nums[i] == 1) ? 1 : -1;

            auto it = firstIndex.find(prefix);
            if (it != firstIndex.end()) {
              
                maxLen = max(maxLen, i - it->second);
            } else {
              
                firstIndex[prefix] = i;
            }
        }
        return maxLen;
    }
};
