class Solution {
public:
    void AllPossiblePermutations(vector<int>&nums,vector<int>&candidate_permutation, vector<vector<int>>&ans_permutations, vector<bool>&visited){
        if(candidate_permutation.size() == nums.size()){
            ans_permutations.push_back(candidate_permutation);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(visited[i] == true) continue;

            visited[i] = true;

            candidate_permutation.push_back(nums[i]);

            AllPossiblePermutations(nums, candidate_permutation, ans_permutations, visited);
            candidate_permutation.pop_back();

            visited[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans_permutations;
        vector<int>candidate_permutation;
        vector<bool>visited(nums.size(), false);
        AllPossiblePermutations(nums, candidate_permutation, ans_permutations, visited);
        return ans_permutations;

    }
};
