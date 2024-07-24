class Solution {
public:
    bool isSafe(int i, int j, int n, int m){
        return (i >= 0 && i< n && j >= 0 && j< m);
    }

    void bfs(vector<vector<char>>& grid, int i, int j, queue<pair<int, int>> &q){
        int n = grid.size(), m = grid[0].size();
        q.push({i, j});
        grid[i][j] = '$';

        vector<int> x = {1, -1, 0, 0};
        vector<int> y = {0, 0, 1, -1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            for(int i=0; i<4; i++){
                int nr = it.first + x[i];
                int nc = it.second + y[i];
                if(isSafe(nr, nc, n, m) && grid[nr][nc] == '1'){
                    q.push({nr, nc});
                    grid[nr][nc] = '$';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)    return 0;
        int n = grid.size(), m = grid[0].size();
        int cnt = 0;
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    bfs(grid, i, j, q);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};