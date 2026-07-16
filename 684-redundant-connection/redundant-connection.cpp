class Solution {
public:
bool dfs(vector<vector<int>>& adj , int currnode  , int destnode , vector<bool>& vis){
    vis[currnode] = true;
    if(currnode ==destnode) return true;
    for(auto &node : adj[currnode]){
        if(!vis[node]){
            if(dfs(adj , node , destnode , vis)) return true;
        }
    }
    return false;
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+1);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            vector<bool> vis(n+1);
            if(!adj[u].empty() && !adj[v].empty()){
                if(dfs(adj , u , v , vis)){
                    return edge;
                }
            }
                 adj[u].push_back(v);
            adj[v].push_back(u);           
        }
        return {};

    }
};