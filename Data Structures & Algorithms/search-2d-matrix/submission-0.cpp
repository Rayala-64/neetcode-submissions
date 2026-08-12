class Solution {
public:
    bool searchInRow(vector<vector<int>> &matrix, int target, int row){
        int m = matrix.size();
        int n = matrix[0].size();

        int start_col = 0;
        int end_col = n - 1;

        while(start_col <= end_col){
            int middle_col = start_col + (end_col - start_col) / 2;

            if(target == matrix[row][middle_col]){
                return true;
            }

            else if(target > matrix[row][middle_col]){
                start_col = middle_col + 1;
            }

            else{
                end_col = middle_col - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int start_row = 0;
        int end_row = m - 1;

        while(start_row <= end_row){
            int middle_row = start_row + (end_row - start_row) / 2;

            if (target >= matrix[middle_row][0] && target <= matrix[middle_row][n - 1]){
                return searchInRow(matrix, target, middle_row);
            }

            else if(target > matrix[middle_row][n - 1]){
                start_row = middle_row + 1;
            }

            else{
                end_row = middle_row - 1;
            }
        }
        return false;
    }
};
