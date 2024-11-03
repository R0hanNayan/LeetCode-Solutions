class Solution {
public:
    void rotate(string &s, int k){
        reverse(s.begin(), s.begin() + k);
        reverse(s.begin()+k, s.end());
        reverse(s.begin(), s.end());
    }
    bool rotateString(string s, string goal) {
        int n1 = s.length();
        int n2 = goal.length();
        
        for(int i = 0; i<n1; i++){
            string rotated = s;
            rotate(rotated, i);
            if(rotated==goal){    return true;    }
        }
        return false;
    }
};