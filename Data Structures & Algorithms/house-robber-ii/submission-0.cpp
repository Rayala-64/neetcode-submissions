class Solution {
public:
    int LinearRobberHelper(int start, int end, vector<int>& nums) {

        vector<int> dp(nums.size(), 0);

        dp[start] = nums[start];

        if (start == end) {
            return dp[start];
        }

        dp[start + 1] = max(nums[start], nums[start + 1]);

        for (int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[end];
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        // Only one house
        if (n == 1) {
            return nums[0];
        }

        // Exclude first house: [1 ... n-1]
        int exclude_first = LinearRobberHelper(1, n - 1, nums);

        // Exclude last house: [0 ... n-2]
        int exclude_last = LinearRobberHelper(0, n - 2, nums);

        return max(exclude_first, exclude_last);
    }
};