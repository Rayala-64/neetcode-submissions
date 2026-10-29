class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq; 
        /*Equivalent to:
priority_queue<int, vector<int>, less<int>> pq;

Default is Max Heap, uses less<int> as default comparison operator.

Suppose we compare 10 and 20.
- less<int> checks whether 10 < 20 → true.
- This means 10 comes before 20 in the comparator's ordering.
- The priority queue's heap rules ensure that 20 has higher priority and appears at the top.
Therefore, pq.top() returns 20.*/

        for(int x : nums){
            pq.push(x);
        } // add all the elements into the heap (max heap named pq)

        for(int i = 1; i < k; i++){
            pq.pop(); // Since, I need to get the kth largest number, I need to pop out k - 1 elements from the container (that used to represent the max heap)
        }

        // For the kth largest element, return the top most element (root node as in tree notation)
        return pq.top();
    }
};
