class Solution {
public:
    int dfs(int i, int j, int rows, int cols, vector<vector<int>>& grid){
            // first check if its out of bounds or we hit water 
            if(i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != 1){
                return 0;
            }

            // mark the current cell, change to 0 so it doesn't get counted again
            // in the recursive call
            grid[i][j] = 0;

            // now recursive call for each all valid blocks in 4 directions
            int area = 1 + dfs(i + 1,j, rows, cols, grid) + dfs(i - 1, j, rows, cols, grid) + dfs(i, j + 1, rows, cols, grid) + dfs(i, j - 1, rows, cols, grid);

            return area;
        }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int max_area = 0;


        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    max_area = max(max_area, dfs(i, j, rows, cols, grid));
                }
            }
        }
        return max_area;
    }
};