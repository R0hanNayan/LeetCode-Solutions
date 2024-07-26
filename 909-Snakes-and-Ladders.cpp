class Solution {
public:
    pair<int, int> getCord(int s, int n) {
        int row = n-1-(s-1)/n;
        
        int col = (s-1)%n;
        
        if((n%2==1 && row%2==1)||(n%2==0 && row%2==0))
            col = n-1-col;
        
        return make_pair(row, col);
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<int> q;
        int step = 0;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[n-1][0] = true;
        q.push(1);

        while(!q.empty()){
            int k = q.size();
            while(k--){
                auto x = q.front();
                q.pop();
                if(x == n*n)    return step;

                for(int i=1; i<=6; i++){
                    if(x+i > n*n){
                        continue;
                    }
                    pair<int, int> cord = getCord(x + i, n);
                    int r = cord.first;
                    int c = cord.second;
                    if(vis[r][c])   continue;
                    vis[r][c] = true;
                    if(board[r][c] == -1){
                        q.push(x + i);
                    }else{
                        q.push(board[r][c]);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};