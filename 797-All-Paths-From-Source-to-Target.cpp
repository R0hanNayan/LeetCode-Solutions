class Solution {
public:
    void getPath(vector<vector<int>>& graph, int s, int d, vector<int> &temp, vector<vector<int>> &res){
        if(s == d){
            res.push_back(temp);
            return;
        }

        for(auto it : graph[s]){
            temp.push_back(it);
            getPath(graph, it, d, temp, res);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> res;
        vector<int> temp;
        temp.push_back(0);
        getPath(graph, 0, n-1, temp, res);
        return res;
    }
};