class Solution {
public:
    void DFSHelper(vector<vector<char>> &grid, vector<vector<bool>> &visited, int row, int col){
        int m = grid.size();
        int n = grid[0].size();

        if(row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == '0' || visited[row][col] == true){
            return;
        }

        visited[row][col] = true;

        DFSHelper(grid, visited, row - 1, col);
        DFSHelper(grid, visited, row + 1, col);
        DFSHelper(grid, visited, row, col - 1);
        DFSHelper(grid, visited, row, col + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool> (n, false));

        int count_islands = 0;

        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(visited[row][col] == false && grid[row][col] == '1'){
                    DFSHelper(grid, visited, row, col);
                    count_islands++;
                }
            }
        }
        return count_islands;
    }
};
