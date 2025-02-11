class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result = "";
        int m = part.length();

        for(char &ch : s) {
            result.push_back(ch);

            if(result.length() >= m && result.substr(result.length() - m) == part) {
                result.erase(result.length() - m);
            }
        }

        return result;
    }
};