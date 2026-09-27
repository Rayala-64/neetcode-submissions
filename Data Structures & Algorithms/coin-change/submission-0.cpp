class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        if(amount == 0) return 0;

        vector<int> minimumDenominationDP(amount + 1);

        for(int i = 1; i <= amount; i++){

            minimumDenominationDP[i] = INT_MAX;

            for(int coin : coins){
                if(coin <= i && minimumDenominationDP[i - coin] != INT_MAX){
                    minimumDenominationDP[i] = min(minimumDenominationDP[i], 1 + minimumDenominationDP[i - coin]);
                }
            }
        }
        
        if(minimumDenominationDP[amount] == INT_MAX) return -1;

        return minimumDenominationDP[amount];
    }
};
