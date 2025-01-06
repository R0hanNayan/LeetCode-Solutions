class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        vector<int> ans(n, 0);
        int cummSum = 0;
        int cummVal = 0;

        for (int i = 0; i < n; i++) {
            ans[i] += cummSum;
            cummVal += boxes[i] == '0' ? 0 : 1;
            cummSum += cummVal;
        }

        cummSum = 0;
        cummVal = 0;

        for (int i = n-1; i >= 0; i--) {
            ans[i] += cummSum;
            cummVal += boxes[i] == '0' ? 0 : 1;
            cummSum += cummVal;
        }

        return ans;
    }
};