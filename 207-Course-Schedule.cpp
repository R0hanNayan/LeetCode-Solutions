class Solution {
public:
    void toposort(vector<int> adj[], int n, vector<int> &indegree, queue<int> &q, vector<int> &res){
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            res.push_back(it);
            for(auto i : adj[it]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        vector<int> res;
        queue<int> q;

        for(auto it : pre){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        toposort(adj, n, indegree, q, res);
        return res.size() == n;
    }
};