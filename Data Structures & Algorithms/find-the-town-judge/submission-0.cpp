class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        if(trust.size() == 0) return -1;

        int m = trust.size();

        vector<int> indegree(n + 1);
        vector<int> outdegree(n + 1);

        for(int i = 1; i <= n; i++){
            for(int j = 0; j < trust.size(); j++){
                if(trust[j][1] == i){
                    indegree[i]++;
                }

                if(trust[j][0] == i){
                    outdegree[i]++;
                }
            }
        }

        for(int i = 1; i <= n; i++){
            if(indegree[i] == n - 1 && outdegree[i] == 0){
                return i;
            }
        }
        
        return -1;
    }
};