class Solution {
public:
    int getLucky(string s, int k) {
        string num  = "";

        for(auto it : s){
            num += to_string((it - 'a') + 1);
        }
        while(k){
            int sum = 0;
            for(auto it : num){
                sum += (it - '0');
            }
            num = to_string(sum); 
            k--;
        }

        return stoi(num);
    }
};