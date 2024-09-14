class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)  return false;
        //a power of two will have only 1 set bit.
        //16 ---> 1 0 0 0 0   (n)
        //15 ---> 0 1 1 1 1   (n-1)
        return (n & (n - 1)) == 0;
    }
};
