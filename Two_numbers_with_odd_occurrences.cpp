class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int N)  
    {
        long num = 0;
        
        for(int i = 0; i < N; i++)  num = num ^ arr[i];
        
        int rightMost = (num & num-1) ^ num;  // rightmost set bit
        
        int b1 = 0, b2 = 0;   // numbers with rightmost set and unset bits
        
        for(int i = 0; i < N; i++){
            if(arr[i] & rightMost){
                b1 = b1 ^ arr[i];
            }else{
                b2 = b2 ^ arr[i];
            }
        }
      
        return {b1, b2};
    }
};
