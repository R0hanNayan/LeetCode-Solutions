class Solution {
public:
    int minLength(string s) {
        int i = 0, j = 1;
        int n = s.size();

        while(j < n){
            if(i < 0){
                i++;
                s[i] = s[j];
            }else if(s[i] == 'A' && s[j] == 'B' || s[i] == 'C' && s[j] == 'D'){
                i--;
            }else{
                i++;
                s[i] = s[j];
            }
            j++;
        }
        return i+1;
    }
};