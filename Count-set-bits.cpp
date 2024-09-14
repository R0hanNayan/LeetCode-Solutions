class Solution{
    public:
    int countSetBits(int n)
    {
        if(n==0){
            return 0;
        }
        else if(n==1){
            return 1;
        }
        int i=log2(n);
        int total=0;
        
        total=((1<<(i-1))*i) + (n-(1<<i)+1) + countSetBits(n-(1<<i));
    }
};
