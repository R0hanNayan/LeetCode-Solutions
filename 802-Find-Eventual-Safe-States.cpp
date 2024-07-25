class Solution {
public:
    vector<bool> toposort(int v, vector<vector<int>> adj, vector<int> &in){
        queue<int> q;
        for(int i=0; i<v; i++){
            if(in[i] == 0){
                q.push(i);
            }
        }

        vector<bool> safe(v, false);
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            safe[it] = true;
            for(auto i : adj[it]){
                in[i]--;
                if(in[i] == 0){
                    q.push(i);
                }
            }
        }
        return safe;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> in(v, 0);
        vector<vector<int>> adj(v);

        for(int i=0; i<v; i++){
            for(auto it : graph[i]){
                adj[it].push_back(i);
                in[i]++;
            }
        }
        vector<bool> safe = toposort(v, adj, in);
        vector<int> res;
        for(int i=0; i<v; i++){
            if(safe[i]){
                res.push_back(i);
            }
        }
        return res;
    }
};