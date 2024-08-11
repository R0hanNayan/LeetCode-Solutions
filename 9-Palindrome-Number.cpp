class Solution {
public:
    bool isPalindrome(int x) {
        int num = x;
        bool flag = true;
        if(num < 0){
            flag = false;
        }
        long rev = 0;
        while(x>0){
            int ld = x%10;
            x /= 10;
            rev = rev * 10 + ld; 
        }
        if(flag && rev==num){
            return true;
        }
        return false;
    }
};