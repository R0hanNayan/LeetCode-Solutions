class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n-1;

        while(j >= 0){
            if(s[i] == s[j]){
                i++;
            }
            j--;
        }

        string remainder = s.substr(i);
        if(remainder.size() == 0)   return s;

        string rev_rem = remainder;
        reverse(rev_rem.begin(), rev_rem.end());

        return rev_rem + shortestPalindrome(s.substr(0, i)) + remainder;
    }
};