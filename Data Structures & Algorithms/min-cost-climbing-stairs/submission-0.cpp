class Solution {
public:
    int MinimumCostHelper(int current_floor, vector<int>&cost, vector<int>&memoize){
        if(current_floor >= cost.size()){
            return 0;
        }

        if(memoize[current_floor] != -1){
            return memoize[current_floor];
        }

        int oneStep = MinimumCostHelper(current_floor + 1, cost, memoize);
        int twoStep = MinimumCostHelper(current_floor + 2, cost, memoize);

        return memoize[current_floor] = cost[current_floor] + min(oneStep, twoStep);
    }

    int minCostClimbingStairs(vector<int>& cost) {

        vector<int> memoize(cost.size(), -1);

        int start_at_0 = MinimumCostHelper(0, cost, memoize);
        int start_at_1 = MinimumCostHelper(1, cost, memoize);

        return min(start_at_0, start_at_1);
    }
};
