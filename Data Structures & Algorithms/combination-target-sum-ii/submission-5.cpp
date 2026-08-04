class Solution {
public:
    void GenerateAllPossibleCombinationSum(
        vector<int>& candidates,
        int currentIdx,
        int target,
        vector<int>& current_combination,
        vector<vector<int>>& ans_combinations
    ) {
        // Base Case
        if (target == 0) {
            ans_combinations.push_back(current_combination);
            return;
        }

        // Try every candidate from currentIdx onwards
        for (int i = currentIdx; i < candidates.size(); i++) {

            // Skip duplicates at the same recursion level
            if (i > currentIdx && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted, no need to continue further
            if (candidates[i] > target)
                break;

            // Choose
            current_combination.push_back(candidates[i]);

            // Explore
            GenerateAllPossibleCombinationSum(
                candidates,
                i + 1,
                target - candidates[i],
                current_combination,
                ans_combinations
            );

            // Undo
            current_combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans_combinations;
        vector<int> current_combination;

        GenerateAllPossibleCombinationSum(
            candidates,
            0,
            target,
            current_combination,
            ans_combinations
        );

        return ans_combinations;
    }
};