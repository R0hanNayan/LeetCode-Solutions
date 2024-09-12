class Solution {
  public:
    int setBit(int n) {
        //n & n - 1 ---> to clear the rightmost set bit
        return n | n + 1;
    }
};
