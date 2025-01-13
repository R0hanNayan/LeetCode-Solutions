class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> mp;

        for(auto it : s){
            mp[it]++;
        }

        int len = 0;
        for(auto it : mp){
            if(it.second == 0)   continue;
            if(it.second % 2 == 0){
                len += 2;
            }else{
                len += 1;
            }
        }

        return len;
    }
};