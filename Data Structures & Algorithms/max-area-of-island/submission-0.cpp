class Solution {
public:
    int DFSHelper(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col){
        int m = grid.size();
        int n = grid[0].size();

        if(row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0 || visited[row][col] == true){
            return 0;
        }

        visited[row][col] = true;

        return (1 + DFSHelper(grid, visited, row - 1, col) + DFSHelper(grid, visited, row + 1, col) + DFSHelper(grid, visited, row, col - 1)  +   DFSHelper(grid, visited, row, col + 1)) ;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool> (n, false));

        int max_area_island = 0;

        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1 && visited[row][col] == false){
                    int area_component = DFSHelper(grid, visited, row, col);
                    max_area_island = max(area_component, max_area_island);
                }
            }
        }
        return max_area_island;
    }
};
