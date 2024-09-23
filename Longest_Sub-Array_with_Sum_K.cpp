class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        int size = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            sum += a[i];
            
            if(sum == k){
                size = max(size, i+1);
            }
            
            if(mp.find(sum - k) != mp.end()){
                size = max(size, i - mp[sum - k]);
            }
            
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
            
        }
        return size;
    } 
};
