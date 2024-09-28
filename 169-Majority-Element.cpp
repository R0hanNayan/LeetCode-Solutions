class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 0, majEl;
        for(int num : nums){
            if(counter == 0){
                majEl = num;
                counter++;
            }else if(num == majEl){
                counter++;
            }else{
                counter--;
            }
        }
        return majEl;
    }
};