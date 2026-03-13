class Solution {
public:
    
    void findCombinations(int index, vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] <= target) {
                current.push_back(candidates[i]);
                findCombinations(i, candidates, target - candidates[i], current, result);
               current.pop_back();
            }
        }
    }
    
   vector<vector<int>>combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        findCombinations(0, candidates, target, current, result);
        return result;
    }
};

