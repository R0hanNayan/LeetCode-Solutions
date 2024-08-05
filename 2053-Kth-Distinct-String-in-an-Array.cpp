class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;

        for(auto it : arr){
            mp[it]++;
        }
        int i = 0;
        for(auto it : arr){
            if(mp[it] == 1){
                i++;
            }
            if(i == k){
                return it;
            }
        }

        
        return "";
    }
};