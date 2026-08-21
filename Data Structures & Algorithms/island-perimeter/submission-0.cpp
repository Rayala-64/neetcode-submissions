class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int perimeter_result = 0;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 1) {

                    // Up
                    if (row == 0 || grid[row - 1][col] == 0) {
                        perimeter_result++;
                    }

                    // Down
                    if (row == m - 1 || grid[row + 1][col] == 0) {
                        perimeter_result++;
                    }

                    // Left
                    if (col == 0 || grid[row][col - 1] == 0) {
                        perimeter_result++;
                    }

                    // Right
                    if (col == n - 1 || grid[row][col + 1] == 0) {
                        perimeter_result++;
                    }
                }
            }
        }

        return perimeter_result;
    }
};