class Solution {
public:
    void bfs(unordered_map<string, vector<pair<string, double>>> &adj, string src, string dst, double &ans) {
    queue<pair<string, double>> q;
    unordered_map<string, double> visited; 

    q.push({src, 1.0});
    visited[src] = 1.0;

    while(!q.empty()) {
        auto [u, product] = q.front();
        q.pop();

        if(u == dst) {
            ans = product;
            return;
        }

        for(auto &[v, val] : adj[u]) {
            if(!visited.count(v)) {
                visited[v] = product * val;
                q.push({v, product * val});
            }
        }
    }

    ans = -1.0; 
}
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& queries) {
        int n = eq.size();
        unordered_map<string, vector<pair<string, double>>> adj;
        vector<double> res;
        // create graph
        for(int i=0; i<n; i++){
            string u = eq[i][0];    //a
            string v = eq[i][1];    //b
            double val = values[i];

            adj[u].push_back({v, val}); //a / b
            adj[v].push_back({u, 1.0 / val});   //b / a
        }

        for(auto it : queries){
            string src = it[0];
            string dest = it[1];
            double ans = -1.0;
            double product = 1.0;

            if(adj.find(src) != adj.end()){
                unordered_set<string> vis;
                bfs(adj, src, dest, ans);
            }
            res.push_back(ans);
        }

        return res;
    }
};