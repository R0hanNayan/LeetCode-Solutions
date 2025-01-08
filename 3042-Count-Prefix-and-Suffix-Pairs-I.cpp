class Solution {
public:
    bool isPrefixAndSuffix(string s1, string s2){
        int n = s1.size(), m = s2.size();
        if(n > m)   return false;
        int i = 0, j = 0;

        while(i < n && j < m){
            if(s1[i] == s2[j]){
                i++;
                j++;
            }else{
                return false;
            }
        }

        int k = n-1, l = m-1;
        while(k >= 0 && l >= 0){
            if(s1[k] == s2[l]){
                k--;
                l--;
            }else{
                return false;
            }
        }

        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(isPrefixAndSuffix(words[i], words[j])){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};