class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0, j = 0;
        int len = 0; 

        unordered_map<char, int> mp;

        while(j < n){
             if (mp.find(s[j]) != mp.end() && mp[s[j]] >= i) {
                i = mp[s[j]] + 1;
            }
            mp[s[j]] = j;
            len = max(len, j - i + 1);
            j++;
        }
        return len;
    }
};