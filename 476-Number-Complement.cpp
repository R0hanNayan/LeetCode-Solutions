class Solution {
public:
    int findComplement(int num) {
        int numBits = (int)log2(num) + 1;
        int i = 0;

        while(i < numBits){
            num = num ^ (1 << i);
            i++;
        }
        
        return num;
    }
};