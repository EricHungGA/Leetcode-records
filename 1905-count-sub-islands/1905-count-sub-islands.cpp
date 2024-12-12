class Solution {
public:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j){
        // check bounds
        // also include checks for if its water or alrdy visited
        if(i < 0 || i >= grid1.size() || j < 0 || j >= grid1[0].size() || 
        grid2[i][j] == 0 || grid2[i][j] == -1){
            // skip if it hits any of these bounds
            return true;
        }
        // mark as visited
        grid2[i][j] = -1;
        
        // check if we hit water on grid1
        bool isSub = (grid1[i][j] == 1);

        // run 4-directionally
        isSub &= dfs(grid1, grid2, i - 1, j); // top
        isSub &= dfs(grid1, grid2, i + 1, j); // bottom
        isSub &= dfs(grid1, grid2, i, j + 1); // right
        isSub &= dfs(grid1, grid2, i, j - 1); // left

        return isSub;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        // if grid 2 has water in a cell, no point in checking it on grid 1
        // maybe only check grid 2, and compare it to grid 1 as we go?
        int result = 0;
        for(int i = 0; i < grid1.size(); i++){
            for(int j = 0; j < grid1[0].size(); j++){
                if(grid2[i][j] == -1 || grid2[i][j] == 0)continue;
                if(dfs(grid1, grid2, i, j)){
                    result++;
                }
            }    
        }
        return result;
    }
};