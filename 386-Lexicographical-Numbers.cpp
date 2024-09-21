class Solution {
public:
    void solve(int curr, int n, vector<int> &res){
        if(curr > n)    return;

        res.push_back(curr);

        for(int nxtDigit = 0; nxtDigit <= 9; nxtDigit++){
            int nxtNum = curr * 10 + nxtDigit;

            if(nxtNum > n)  return;

            solve(nxtNum, n, res);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;

        for(int num = 1; num <= 9; num++){
            solve(num, n, res);
        }
        return res;
    }
};