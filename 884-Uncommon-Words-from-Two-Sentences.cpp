class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        string temp = "";
        for(auto it : s1){
            if(it == ' '){
                mp[temp]++;
                temp = "";
            }else{
                temp += it;
            }
        }
        mp[temp]++;
        temp = "";
        for(auto it : s2){
            if(it == ' '){
                mp[temp]++;
                temp = "";
            }else{
                temp += it;
            }
        }
        mp[temp]++;
        vector<string> res;
        for(auto it : mp){
            if(it.second == 1){
                res.push_back(it.first);
            }
        }
        return res;
    }
};