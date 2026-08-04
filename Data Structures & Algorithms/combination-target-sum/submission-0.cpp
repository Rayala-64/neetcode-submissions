class Solution {
public:
    void GenerateAllPossibleCombinationSum(vector<int>&nums, int currentIdx, vector<int>&current_combination, vector<vector<int>>&ans_combinations, int target_sum){
        if(currentIdx == nums.size()){
            if(target_sum == 0){
                ans_combinations.push_back(current_combination);
            }
            return;
        }

        if(nums[currentIdx] <= target_sum){
            current_combination.push_back(nums[currentIdx]);
            GenerateAllPossibleCombinationSum(nums, currentIdx, current_combination, ans_combinations, target_sum - nums[currentIdx]);
            current_combination.pop_back();
        }

        GenerateAllPossibleCombinationSum(nums, currentIdx + 1, current_combination, ans_combinations, target_sum);

    }


    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans_combinations;
        vector<int>current_combination;
        GenerateAllPossibleCombinationSum(nums, 0, current_combination, ans_combinations, target);
        return ans_combinations;
    }
};
