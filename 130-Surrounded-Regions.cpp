class Solution {
public:
    bool isSafe(int i, int j, int n, int m){
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    void bfs(vector<vector<char>>& board, int i, int j, queue<pair<int, int>> &q){
        int n = board.size(), m = board[0].size();
        q.push({i, j});
        board[i][j] = '#';
        int x[] = {1, -1, 0, 0};
        int y[] = {0, 0, 1, -1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            for(int k = 0; k < 4; k++){
                int nr = it.first + x[k];
                int nc = it.second + y[k];

                if(isSafe(nr, nc, n, m) && board[nr][nc] == 'O'){
                    q.push({nr, nc});
                    board[nr][nc] = '#';
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        queue<pair<int, int>> q;

        //borders
        for(int i=0; i<n; i++){
            if(board[i][0] == 'O')  bfs(board, i, 0, q);
            if(board[i][m-1] == 'O')  bfs(board, i, m-1, q);
        }
        for(int j=0; j<m; j++){
            if(board[0][j] == 'O')  bfs(board, 0, j, q);
            if(board[n-1][j] == 'O')  bfs(board, n-1, j, q);
        }

        //remaining inside borders
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O')  board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};