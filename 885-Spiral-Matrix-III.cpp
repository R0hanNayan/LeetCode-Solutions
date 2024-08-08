class Solution {
public:
    bool outOfBound(int r, int c, int n ,int m){
        return r < 0 || r >= n || c < 0 || c >= m;
    }
    vector<vector<int>> spiralMatrixIII(int r, int c, int rs, int cs) {
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> res;
        int step = 0;
        int d = 0;
        res.push_back({rs, cs});
        
        while(res.size() < r * c){
            if(d == 0 || d == 2)    step++;

            for(int i = 0; i < step; i++){
                rs += dir[d][0];
                cs += dir[d][1];

                if(!outOfBound(rs, cs, r, c)){
                    res.push_back({rs, cs});
                }
            }

            d = (d + 1) % 4;
        }
        return res;
    }
};