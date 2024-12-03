class Solution {
private:
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& visited, int prev_height){
        // stop the dfs if we are out of bounds, or the current cell is shorter than the previous
        // or if we already visited this cell then no need to re-calculate
        if(r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size() 
        || heights[r][c] < prev_height || visited[r][c]){
            return;
        }
        visited[r][c] = true;

        // now check all 4 directions
        dfs(heights, r + 1, c, visited, heights[r][c]); // DOWN
        dfs(heights, r - 1, c, visited, heights[r][c]); // UP
        dfs(heights, r, c + 1, visited, heights[r][c]); // RIGHT
        dfs(heights, r, c - 1, visited, heights[r][c]); // LEFT
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // DFS approach where we work from the cells of the ocean 
        // (less than doing every cell in our matrix) and check for routes
        // leading to pacific, and separately routes leading to atlantic
        // then just cross reference and find the cells that are true for both

        // edge case where heights is empty
        if(heights.empty())return{};

        int rows = heights.size();
        int cols = heights[0].size();

        // call DFS for each row bordering pacific and atlantic, then column
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        // top row of pacific
        for(int c = 0; c < cols; c++){
            dfs(heights, 0, c, pacific, INT_MIN);
        }
        // left column for pacific
        for(int r = 0; r < rows; r++){
            dfs(heights, r, 0, pacific, INT_MIN);
        }
        // right column for atlantic
        for(int r = 0; r < rows; r++){
            dfs(heights, r, cols - 1, atlantic, INT_MIN);
        }
        // bottom row for atlantic
        for(int c = 0; c < cols; c++){
            dfs(heights, rows - 1, c, atlantic, INT_MIN);
        }

        // now check for the overlap
        vector<vector<int>> result;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(pacific[r][c] && atlantic[r][c]){
                    result.push_back({r,c});
                }
            }
        }

        return result;
    }
};