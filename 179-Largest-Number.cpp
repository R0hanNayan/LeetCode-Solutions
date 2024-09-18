class Solution {
public:
    static bool myCmp(int a, int b){
        string _a = to_string(a);
        string _b = to_string(b);
        string res1 = _a + _b;
        string res2 = _b + _a;
        return res1 > res2;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), myCmp);
        string res = \\;
        for(auto it : nums){
            res += to_string(it);
        }
        
        return res[0] == '0' ? \0\ : res;
    }
};