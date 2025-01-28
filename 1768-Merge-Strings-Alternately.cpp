class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        int i = 0, j = 0;

        string res = "";

        while(i < n && j < m){
            res += word1[i];
            i++;
            res += word2[j];
            j++;
        }

        while(i < n){
            res += word1[i];
            i++;
        }

        while(j < m){
            res += word2[j];
            j++;
        }
        return res;
    }
};