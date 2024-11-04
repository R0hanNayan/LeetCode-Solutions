class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g), end(g));
        sort(begin(s), end(s));

        int i = 0, j = 0;
        int n1 = g.size(), n2 = s.size();

        while(i < n1 && j < n2){
            if(s[j] >= g[i]){
                i++;
            }
            j++;
        }
        return i;
    }
};