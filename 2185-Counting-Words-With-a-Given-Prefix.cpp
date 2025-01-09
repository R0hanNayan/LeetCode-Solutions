class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.size();
        int cnt = 0;
        for(auto word : words){
            string substr = word.substr(0, n);
            if(pref == substr){
                cnt++;
            }
        }

        return cnt;
    }
};