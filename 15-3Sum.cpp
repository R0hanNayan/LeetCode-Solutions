class Solution {
public:
    void twoSum(vector<int> &nums, int k, int t, vector<vector<int>> &res){
        int i = k, j = nums.size()-1;
        while(i < j){
            if(nums[i] + nums[j] == t){
                res.push_back({-t, nums[i], nums[j]});
                while(i < j && nums[i] == nums[i+1])    i++;
                while(i < j && nums[j] == nums[j-1])    j--;
                i++;
                j--;
            }else if(nums[i] + nums[j] > t){
                j--;
            }else{
                i++;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i = 0; i < n-2; i++){
            if(i != 0 && nums[i] == nums[i-1])  continue;
            twoSum(nums, i+1, -nums[i], res);   // n1 + n2 + n3 == 0 ---> n1 + n2 = -n3
        }
        return res;
    }
};