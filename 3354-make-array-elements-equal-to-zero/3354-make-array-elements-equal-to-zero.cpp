class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        long long sum = 0;
        for (int num : nums) sum += num;

        long long preSum = 0;
        int res = 0;

        for (int num : nums) {
            preSum += num;
            if (num == 0) {
                if (preSum * 2 == sum)
                    res += 2;
                else if (abs(preSum * 2 - sum) == 1)
                    res += 1;
            }
        }

        return res;
    }
};
