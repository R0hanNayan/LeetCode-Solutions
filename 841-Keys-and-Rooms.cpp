class Solution {
public:
    bool bfs(vector<int> adj[], int s, int d, int n){
        queue<int> q;
        vector<bool> vis(n, false);
        vis[s] = true;
        q.push(s);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = true;
                }
            }
        }
        for(auto it : vis){
            if(!it) return false;
        }
        return true;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<int> adj[n];
        for(int i = 0; i < n; i++){
            for(auto it : rooms[i]){
                adj[i].push_back(it);
            }
        }

        return bfs(adj, 0, n-1, n);
    }
};