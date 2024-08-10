class Solution {
public:
    bool isSafe(int i, int j, int n, int m){
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    void bfs(vector<vector<int>> &graph, int i, int j, queue<pair<int, int>> &q){
        int n = graph.size();
        q.push({i, j});
        graph[i][j] = 2;

        vector<int> x = {1, -1, 0, 0};
        vector<int> y = {0, 0, 1, -1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            for(int k=0; k<4; k++){
                int nr = it.first + x[k];
                int nc = it.second + y[k];
                if(isSafe(nr, nc, n, n) && graph[nr][nc] == 0){
                    q.push({nr, nc});
                    graph[nr][nc] = 2;
                }
            }
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> graph(n*3, vector<int>(n*3, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '/'){
                    graph[i*3][j*3+2] = 1;  //(0, 2)
                    graph[i*3+1][j*3+1] = 1;    //(1, 1)
                    graph[i*3+2][j*3] = 1;  //(2, 0)
                }else if(grid[i][j] == '\\'){
                    graph[i*3][j*3] = 1;    //(0, 0)
                    graph[i*3+1][j*3+1] = 1;    //(1, 1)
                    graph[i*3+2][j*3+2] = 1;    //(2, 2)
                }
            }
        }

        int cnt = 0;
        queue<pair<int, int>> q;

        for(int i = 0; i < 3*n; i++){
            for(int j = 0; j < 3*n; j++){
                if(graph[i][j] == 0){
                    bfs(graph, i, j, q);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};