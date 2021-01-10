class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        
        if (rows == 0) return -1;
        
        int cols = grid[0].size();
        
        int numFresh = 0;
        
        queue<pair<int, int>> q;
        
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    numFresh++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        
        int minutes = 0;
        
        while (q.size() && numFresh > 0) {
            
            int len = q.size();
            
            minutes++;
            
            for (int i = 0; i < len; i++) {
                auto curr = q.front(); 
                int x = curr.first, y = curr.second;
                q.pop();
                
                for (auto p : dir) {
                    int xx = x + p.first;
                    int yy = y + p.second;
                    
                    if (xx >= 0 && xx < grid.size() && yy >= 0 && yy < grid[0].size() && grid[xx][yy] == 1 ) {
                        numFresh--;
                        grid[xx][yy] = 2;
                        q.push({xx, yy});
                    }
                }
            }
        }
        
        return (numFresh == 0) ? minutes : -1;
    }
};