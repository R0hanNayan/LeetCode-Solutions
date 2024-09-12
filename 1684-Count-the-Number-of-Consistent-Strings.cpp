class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> mp;

        for(auto it : allowed){
            mp[it]++;
        }
        int cnt = 0;
        for(auto it : words){
            bool flag = true;
            for(int i=0; i<it.size(); i++){
                if(mp.find(it[i]) == mp.end()){
                    flag = false;
                    break;
                }
            }
            if(flag)    cnt++;
        }
        return cnt;
    }
};