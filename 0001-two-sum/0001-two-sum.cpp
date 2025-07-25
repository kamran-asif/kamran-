class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // ek hash-map bana rahe hain: number (value) → uska index
        unordered_map<int,int> mp; 
        
        // ek hi pass mein array traverse karenge
        for (int i = 0; i < nums.size(); i++) {
            // current number ka complement jo target complete karega
            int need = target - nums[i];
            
            // check karo kya ye complement pehle map mein aa chuka hai?
            auto it = mp.find(need);
            if (it != mp.end()) {
                // agar mila, to uska index aur current index return kar do
                return { it->second, i };
            }
            
            // agar nahi mila, to abhi wala number map mein daal do
            // future indices iska complement dhoondenge
            mp[nums[i]] = i;
        }
        
        // problem statement ke hisaab se ek solution hamesha milega,
        // lekin safe side pe ye return rakh rahe hain
        return { -1, -1 };
    }
};
