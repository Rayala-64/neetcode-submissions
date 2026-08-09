class Solution {
public:
    int DPHelper(int steps_no, vector<int> &dp){

        if(steps_no == 1 || steps_no == 2) return steps_no;

        if(dp[steps_no] != -1) return dp[steps_no];

        return dp[steps_no] = DPHelper(steps_no - 1, dp) + DPHelper(steps_no - 2, dp);

    }
    /*int climbStairs(int n) {
        if(n == 1 || n == 2) return n;

        return climbStairs(n - 1) + climbStairs(n - 2);
    }*/
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);

        int result = DPHelper(n, dp);

        return result;
    }
};
