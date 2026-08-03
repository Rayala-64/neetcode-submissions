class Solution {
public:
    void GenerateAllSubsets(vector<int>&nums, int currentIdx, vector<int>&current_element, vector<vector<int>>&ans_subsets){
        if(currentIdx == nums.size()){
           ans_subsets.push_back(current_element);
           return;
        }

        current_element.push_back(nums[currentIdx]);
        GenerateAllSubsets(nums, currentIdx + 1, current_element, ans_subsets);

        current_element.pop_back();

        GenerateAllSubsets(nums, currentIdx + 1, current_element, ans_subsets);
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans_subsets;
        vector<int> current_element;

        GenerateAllSubsets(nums, 0, current_element, ans_subsets);
        return ans_subsets;
    }
};
