class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)  return 1;
        int numBits = (int)log2(n) + 1;
        int i = 0;

        while(i < numBits){
            n = n ^ (1 << i);
            i++;
        }
        return n;
    }
};