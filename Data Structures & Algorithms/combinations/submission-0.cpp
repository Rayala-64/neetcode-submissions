class Solution {
public:
    void GenerateAllPossibleCombinations(
        vector<int>& input_array,
        int currentIndex,
        vector<int>& current_combination,
        vector<vector<int>>& ans_combinations,
        int upper_range,
        int combination_size)
    {
        // Combination completed
        if(current_combination.size() == combination_size)
        {
            ans_combinations.push_back(current_combination);
            return;
        }

        // Processed all elements
        if(currentIndex == upper_range)
            return;

        // Include
        current_combination.push_back(input_array[currentIndex]);
        GenerateAllPossibleCombinations(
            input_array,
            currentIndex + 1,
            current_combination,
            ans_combinations,
            upper_range,
            combination_size);

        current_combination.pop_back();

        // Exclude
        GenerateAllPossibleCombinations(
            input_array,
            currentIndex + 1,
            current_combination,
            ans_combinations,
            upper_range,
            combination_size);
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans_combinations;
        vector<int> current_combination;
        vector<int> input_array(n);

        for(int i = 0; i < n; i++)
            input_array[i] = i + 1;

        GenerateAllPossibleCombinations(
            input_array,
            0,
            current_combination,
            ans_combinations,
            n,
            k);

        return ans_combinations;
    }
};