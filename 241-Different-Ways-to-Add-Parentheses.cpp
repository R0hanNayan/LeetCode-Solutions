class Solution {
public:
    vector<int> solve(string s){
        vector<int> res;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '+' || s[i] == '-' || s[i] == '*'){
                vector<int> left = solve(s.substr(0, i));
                vector<int> right = solve(s.substr(i+1));

                for(auto x : left){
                    for(auto y : right){
                        if(s[i] == '+'){
                            res.push_back(x + y);
                        }else if(s[i] == '-'){
                            res.push_back(x - y);
                        }else{
                            res.push_back(x * y);
                        }
                    }
                }
            }
        }
        if(res.empty()) {
            res.push_back(stoi(s));
        }
        return res;
    }
    vector<int> diffWaysToCompute(string exp) {
        return solve(exp);
    }
};