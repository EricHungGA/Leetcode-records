class Solution {
private:
    // 4 directions possible to move for each cell
    //                            down     up    right   left
    vector<pair<int, int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    // helper function using dfs to find the FIRST island
    void dfs(vector<vector<int>>&grid, int i, int j, vector<pair<int, int>>&island){
        // all cases where we are out of bounds or we hit a cell of water
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1){
            return;
        }

        // now that we've hit land, mark it in our grid and island vector
        grid[i][j] = 2;
        island.push_back({i,j});

        // recursive call in all 4 directions
        for(const auto& d: dir){
            dfs(grid, i + d.first, j + d.second, island);
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>>first_island;
        bool found = false;

        // gathering coordinates for first island
        for(int i = 0; i < n && !found; i++){
            for(int j = 0; j < n && !found; j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j, first_island);
                    found = true;
                }
            }
        }

        // now we can start our BFS from the first island as a starting point, to the second
        queue<pair<int, int>> q;
        // grid of distance for each cell, -1 is just our random default value that isn't 0 or 2
        vector<vector<int>> dist(n, vector<int>(n, -1));

        // add all coordinates of the first island to queue
        for(const auto&cell : first_island){
            q.push(cell);
            dist[cell.first][cell.second] = 0;
        }

        // BFS loop
        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();

            // check in all 4 directions
            for(const auto&d : dir){
                int new_i = i + d.first;
                int new_j = j + d.second;
                
                // check for valid cell of water to convert
                if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && dist[new_i][new_j] == -1){
                    // if we hit second island, return the dist
                    if(grid[new_i][new_j] == 1){
                        return dist[i][j];
                    }

                    // continue implementing the search
                    dist[new_i][new_j] = dist[i][j] + 1;
                    q.push({new_i, new_j});
                }
            }
        }

        return 0;

    }
};