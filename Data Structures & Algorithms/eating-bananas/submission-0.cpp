class Solution {
public:
    bool canEatBananas(vector<int>& piles, int hour_limit, int speed){
        int total_hours = 0;

        for(int pile : piles){
            total_hours += (pile + speed - 1) / speed;
        }

        return total_hours <= hour_limit;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int minSpeed = 1;

        int maxSpeed = 0;
        for(int pile : piles){
            maxSpeed = max(maxSpeed, pile);
        }

        while(minSpeed < maxSpeed){
            int mid = minSpeed + (maxSpeed - minSpeed)/2;

            if(canEatBananas(piles, h, mid))
               maxSpeed = mid;
            else
               minSpeed = mid + 1;
        }
        return minSpeed;
    }
};
