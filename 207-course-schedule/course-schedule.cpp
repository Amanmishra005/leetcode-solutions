class Solution {
public:
    bool dfs(int currnode , int numCourses , vector<vector<int>>& adj , vector<bool>& vis,vector<bool>& inrecursion ){
        vis[currnode] = true;
        inrecursion[currnode] = true;
        for(auto &i : adj[currnode]){
            if(vis[i]==false && dfs(i , numCourses ,adj, vis,  inrecursion)) return true;
            else if(inrecursion[i]==true) return true;
        }
        inrecursion[currnode] = false;
        return false;
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &prerequisite : prerequisites){
            int u = prerequisite[0];
            int v = prerequisite[1];
            adj[v].push_back(u);
        }
        vector<bool> vis(numCourses , false);
        vector<bool> inrecursion(numCourses , false);
        for(int i=0;i<adj.size();i++){
            if(!vis[i] && dfs(i , numCourses , adj , vis , inrecursion)) return false; 
        }
        return true;
    }
};