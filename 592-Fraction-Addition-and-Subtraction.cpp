class Solution {
public:
    string fractionAddition(string e) {
        int i = 0;
        int n = e.size();
        int num = 0;
        int den = 1;

        while(i < n){
            int currNum = 0;
            int currDen = 0;

            bool isNeg = (e[i] == '-');

            if(e[i] == '+' || e[i] == '-'){
                i++;
            }

            //build numerator
            while(i < n && isdigit(e[i])){
                int val = e[i] - '0';
                currNum = (currNum * 10) + val;
                i++;
            }

            i++;
            if(isNeg)   currNum *= -1;

            //build denominator
            while(i < n && isdigit(e[i])){
                int val = e[i] - '0';
                currDen = (currDen * 10) + val;
                i++;
            }

            num = num * currDen + den * currNum;
            den = den * currDen;
        }

        int gcd = abs(__gcd(num, den));
        num /= gcd;
        den /= gcd;

        return to_string(num) + \/\ + to_string(den);
    }
};