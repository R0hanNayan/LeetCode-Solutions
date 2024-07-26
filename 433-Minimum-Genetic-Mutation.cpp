class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        vector<char> mut = {'A', 'C', 'G', 'T'};
        unordered_set<string> dict(bank.begin(), bank.end());

        if(dict.find(end) == dict.end())    return -1;

        queue<string> q;
        q.push(start);
        int step = 0;

        while(!q.empty()){
            int k = q.size();
            while(k--){
                string curr = q.front();
                q.pop();
                if(curr == end) return step;

                dict.erase(curr);
                for(int i = 0; i < 8; i++){
                    char og = curr[i];
                    for(auto it : mut){
                        curr[i] = it;
                        if(dict.find(curr) != dict.end()){
                            q.push(curr);
                        }
                    }
                    curr[i] = og;
                }
            }
            step++;
        }
        return -1;
    }
};