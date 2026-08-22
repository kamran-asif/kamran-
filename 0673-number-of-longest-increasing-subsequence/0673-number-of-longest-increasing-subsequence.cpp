class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        // length[i] = LIS ki maximum length jo nums[i] par end hoti hai
        vector<int> length(n, 1);

        // cnt[i] = itni maximum-length LIS hain jo nums[i] par end hoti hain
        vector<int> cnt(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {

                if (nums[j] < nums[i]) {

                    // Better/longer LIS mil gayi
                    if (length[j] + 1 > length[i]) {
                        length[i] = length[j] + 1;

                        // Purani count discard
                        cnt[i] = cnt[j];
                    }

                    // Same maximum length ki another LIS mili
                    else if (length[j] + 1 == length[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
        }

        // Overall maximum LIS length
        int maxLength = *max_element(length.begin(), length.end());

        // Maximum length wali sab LIS ka count
        int result = 0;

        for (int i = 0; i < n; i++) {
            if (length[i] == maxLength) {
                result += cnt[i];
            }
        }

        return result;
    }
};