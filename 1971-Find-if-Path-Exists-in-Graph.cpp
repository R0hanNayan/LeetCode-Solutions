class Solution {
public:
    bool bfs(vector<int> adj[], int s, int d, queue<int> &q, vector<bool> &vis){
        q.push(s);
        vis[s] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node == d) return true;
            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = true;
                }
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        vector<int> adj[n];
        vector<bool> vis(n, false);
        queue<int> q;

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        return bfs(adj, s, d, q, vis);
    }
};