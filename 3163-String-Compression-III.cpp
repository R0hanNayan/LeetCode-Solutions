class Solution {
public:
    string compressedString(string word) {
        string comp = "";

        long long curr = 1;
        int n = word.size();

        for(int i = 0; i < n; i++){
            char c = word[i];
            while(i < n-1 && word[i] == word[i+1]){
                i++;
                curr++;
                if(curr == 9){
                    break;
                }
            }
            comp += to_string(curr);
            comp += c;
            curr = 1;
        }
        return comp;
    }
};