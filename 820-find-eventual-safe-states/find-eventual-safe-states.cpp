class Solution {
public:
bool safenode(vector<vector<int>>& graph , int src , vector<bool>& vis , vector<bool>& inrecursion){
    vis[src] = true;
    inrecursion[src] = true;
    for(int &v : graph[src]){
        if(!vis[v] && safenode(graph,v , vis, inrecursion)) return true;
        else if(inrecursion[v]==true) return true;
    }
    inrecursion[src] = false;
    return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> vis(V, false);
        vector<bool> inrecursion(V, false);
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(!vis[i]) safenode(graph , i , vis , inrecursion);
        }
        for(int i=0;i<inrecursion.size();i++){
            if(inrecursion[i]==false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};