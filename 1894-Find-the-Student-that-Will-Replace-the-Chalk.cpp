class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);
        k = k % sum;
        long long i = 0;
        while(k >= chalk[i%n]){
            k -= chalk[i % n];
            i++;
        }

        return i % n;
    }
};