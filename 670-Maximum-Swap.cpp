class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.size();
        
        vector<int> nge(n);
        nge[n-1] = n-1; 
        for(int i = n-2; i >= 0; i--) {
            if(str[i] > str[nge[i+1]]) {
                nge[i] = i; 
            } else {
                nge[i] = nge[i+1]; 
            }
        }

        for(int i = 0; i < n; i++) {
            if(str[nge[i]] > str[i]) {
                swap(str[nge[i]], str[i]);
                break; 
            }
        }

        return stoi(str);
    }
};
