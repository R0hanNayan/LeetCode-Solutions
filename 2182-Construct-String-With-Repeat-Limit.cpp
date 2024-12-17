class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        int n = s.size();
        vector<int> count(26, 0);
        string res = "";

        for(char ch : s){
            count[ch - 'a']++;
        }

        int i = 25;
        while(i >= 0){
            if(count[i] == 0){
                i--;
                continue;
            }

            char ch = 'a' + i;
            int freq = min(count[i], limit);
            res.append(freq, ch);

            count[i] -= freq;

            if(count[i] > 0){
                int j = i -1;
                while(j >= 0 && count[j] == 0){
                    j--;
                }

                if(j < 0){
                    break;
                }

                res.push_back('a' + j);
                count[j]--;
            }
        }
        return res;
    }
};