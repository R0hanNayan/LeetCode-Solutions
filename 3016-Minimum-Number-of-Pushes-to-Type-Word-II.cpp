class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;
        for(auto it : word){
            mp[it]++;
        }

        vector<int> frequencies;
        for(auto it : mp){
            frequencies.push_back(it.second);
        }

        sort(frequencies.begin(), frequencies.end(), greater<int>());

        int cnt = 0;
        for(int i = 0; i < frequencies.size(); i++) {
            if(i < 8) {
                cnt += frequencies[i];
            } else if(i < 16) {
                cnt += frequencies[i] * 2;
            } else if(i < 24) {
                cnt += frequencies[i] * 3;
            } else {
                cnt += frequencies[i] * 4;
            }
        }
        return cnt;
    }
};