class Solution {
public:
    int minFlips(string target) {
        int i = target.find('1');
        if(i == -1) return 0;

        char initial = '0';
        int cnt = 0;
        
        while(i < target.size()){
            if(target[i] != initial){
                cnt++;
                initial = target[i];
            }
            i++;
        }
        return cnt;
    }
};