class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int n = mat.size(), m = mat[0].size();

        int i = 0, j = m-1;

        while(i < n && j >= 0){
            if(mat[i][j] == t){
                return true;
            }else if(mat[i][j] < t){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
};