class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        
        // keeps track of our number of islands
        int num = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                // we see a 1, we want to traverse the whole island
                // using BFS
                if (grid[i][j] == '1') {
                    num += bfs(grid, i, j);
                }
            }
        }
        
        return num;
    }
    
    int bfs(vector<vector<char>>& grid, int i, int j) {
        // delta table
        const int dr[4] = {-1, 1, 0, 0};
        const int dc[4] = { 0, 0, -1, 1};
        
        // create queue for BFS
        queue<pair<int, int>> q;
        
        // mark current node as visited
        grid[i][j] = '0';
        
        // push visited node into queue
        q.push(make_pair(i, j));
        
        while (!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();
            
            int x = node.first, y = node.second;
            
            // visit all neighbors of node
            for (int k = 0; k < 4; k++) {
                int xr = x + dr[k];
                int yr = y + dc[k];
                if (valid(grid, xr, yr) && grid[xr][yr] == '1') {
                    // mark as visited
                    grid[xr][yr] = '0';
                    // push into queue
                    q.push(make_pair(xr, yr));
                }
            }
        }
            
        return 1;
    }
    
    bool valid(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size())
            return false;
        return true;
    }
};