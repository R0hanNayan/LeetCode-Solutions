class Solution {
public:
    vector<vector<int>> subsets(vector<int>& ip) {
        vector<vector<int>> ans;
        int n = ip.size();
        int power = 1 << n;

        for(int num = 0; num < power; num++){
            vector<int> temp;
            for(int i = 0; i < n; i++){
                if(num & (1 << i))
                    temp.push_back(ip[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};