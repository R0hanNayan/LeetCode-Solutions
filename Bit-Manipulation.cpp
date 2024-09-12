class Solution {
  public:
    void bitManipulation(int num, int i) {
        cout<<((num >> i-1) & 1)<<" ";      //get
        cout<<(num | (1 << i-1))<<" ";      //set
        cout<<(num &  ~(1 << i-1))<<" ";    //clear
    }
};
