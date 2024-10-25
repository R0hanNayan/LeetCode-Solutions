class Solution {
public:
    static bool myCmp(string a, string b){
        return a.size() < b.size();
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end(), myCmp);
        vector<string> res;
        unordered_set<string> st;

        for(auto it : folder){
            string curr = "";
            for(int j = 0; j < it.size(); j++){
                curr += it[j];
                if(it[j+1] == '/' && st.find(curr) != st.end()){
                    curr = "";
                    break;
                }
            }
            if(curr != ""){
                st.insert(curr);
                res.push_back(curr);
            }
        }

        return res;
    }
};