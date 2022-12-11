class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // this is a implicit graph problem
        int n_islands = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) // x coords
            for (int j = 0; j < grid[i].size(); j++) // y coord
                if (!visited[i][j] && grid[i][j] == '1')
                    dfs(visited, grid, i, j), n_islands++;
        return n_islands;
    }
private:
    void dfs(vector<vector<bool>>& visited, vector<vector<char>> const& grid, int x, int y){
        visited[x][y] = true;
        vector<pair<int, int>> coord_adj{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (int i = 0; i < coord_adj.size(); i++){
            int new_x = x + coord_adj[i].first;
            int new_y = y + coord_adj[i].second;
            if (!outOfGrid(new_x, new_y, grid.size(), grid[x].size()) && !visited[new_x][new_y]
                && grid[new_x][new_y] == '1')
                dfs(visited, grid, new_x, new_y); // run another dfs
        }
    }
    bool outOfGrid(int x, int y, int size_x, int size_y){
        return x >= size_x || y >= size_y || x < 0 || y < 0; 
    }
};

//   0
// 0 1 0
//   0
