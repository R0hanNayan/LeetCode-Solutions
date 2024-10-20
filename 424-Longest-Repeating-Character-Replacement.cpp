class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        int len = 0;
        int freq = 0;

        while(j < n){
            mp[s[j]]++;  
            freq = max(freq, mp[s[j]]);  
            //maxLen - maxFreq > k
            if ((j - i + 1) - freq > k) {
                mp[s[i]]--; 
                i++;  
            }

            len = max(len, j - i + 1);
            j++; 
        }

        return len;
    }
};