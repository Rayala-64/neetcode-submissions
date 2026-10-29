class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result(k, vector<int> (2, 0));

        priority_queue<
    pair<int, pair<int, int>>,
    vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>
> min_pq;

        for(int i = 0; i < points.size(); i++){

            int x = points[i][0];
            int y = points[i][1];

            int dist = x * x + y * y;

            min_pq.push({dist, {x, y}});
        }

        for (int i = 0; i < k; i++) {
            auto curr = min_pq.top();

            result[i][0] = curr.second.first;
            result[i][1] = curr.second.second;

            min_pq.pop();
        }

        return result;
    }
};
