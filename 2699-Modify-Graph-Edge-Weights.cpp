class Solution {
public:
    vector<pair<int, int>> adj[101];
    vector<int> bfs(int n,int src,int des){
        vector<int>vis(n,0), dis(n,1e9+1);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});

        dis[src] = 0;
        while(!pq.empty()){
            auto [wt,node] = pq.top();
            pq.pop();
            if(vis[node])continue;
            vis[node] = 1;
            for(auto& [newNode,newWt] : adj[node]){
                if(dis[newNode] > wt+newWt){
                    dis[newNode] = wt+newWt;
                    pq.push({wt+newWt, newNode});
                }
            }
        }
        return dis;
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int des, int target) {
        // step 1
        for(auto &it : edges){
            if(it[2] == -1)continue;
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});            
            adj[v].push_back({u,w});
        }
        // step 2
        vector<int>dis = bfs(n,src,des);
        // step 3
        if(dis[des] < target)
        return {};
        // step 4
        if(dis[des] == target){
            for(auto &it : edges){
                if(it[2] == -1)it[2] = 2e9;
            }
            return edges;
        }
        // step 5
        for(int i=0;i<edges.size();i++){

            if(edges[i][2] == -1){

                int u = edges[i][0],v = edges[i][1];

                edges[i][2] = 1;

                adj[u].push_back({v,1});
                adj[v].push_back({u,1});

                vector<int>dist = bfs(n,src,des);
                if(dist[des] <= target){

                    edges[i][2] += target-dist[des];

                for(int j = i+1; j<edges.size();j++){
                    if(edges[j][2] == -1){
                        edges[j][2] = 1e9;
                    }
                }
                return edges;
                }
            }
        }
        return {};
    }
};