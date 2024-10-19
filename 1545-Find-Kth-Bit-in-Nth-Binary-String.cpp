class Solution {
public:
    string generateStr(string s){
        string res = "";
        res = res + s;
        res += "1";
        string temp = "";
        for(auto it : s){
            if(it == '1'){
                temp += '0';
            }else{
                temp += '1';
            }
        }
        reverse(temp.begin(), temp.end());
        res += temp;
        return res;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i = 0; i < n-1; i++){
            s = generateStr(s);
        }

        cout<<s;
        return s[k-1];
    }
};