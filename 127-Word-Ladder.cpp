class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(dict.find(end) == dict.end())    return 0;

        queue<string> q;
        q.push(begin);
        int step = 1;

        while(!q.empty()){
            int k = q.size();
            while(k--){
                string curr = q.front();
                q.pop();
                if(curr == end) return step;
                dict.erase(curr);

                for(int i=0; i<curr.size(); i++){
                    char og = curr[i];
                    for(char ch = 'a'; ch <= 'z'; ch++){
                        curr[i] = ch;
                        if(dict.find(curr) != dict.end()){
                            q.push(curr);
                        }
                    }
                    curr[i] = og;
                }
            }
            step++;
        }
        return 0;
    }
};