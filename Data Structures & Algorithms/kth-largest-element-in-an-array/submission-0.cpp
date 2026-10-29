class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq; //Max Heap 

        for(int x : nums){
            pq.push(x);
        }

        for(int i = 1; i < k; i++){
            pq.pop();
        }

        return pq.top();
    }
};
