class Solution {
public:
bool hasCycle;
void dfs(int currnode,int numCourses ,vector<vector<int>>& adj , vector<bool>& vis , stack<int>& st,vector<bool>& inrecursion){
    vis[currnode] = true;
    inrecursion[currnode] = true;
    for(auto &it : adj[currnode]){
        if(inrecursion[it]==true) {
            hasCycle = true;
            return;
        }
        if(!vis[it]) dfs(it , numCourses , adj , vis,st,inrecursion);
    }
    inrecursion[currnode] = false;
    st.push(currnode);
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &prerequisite : prerequisites){
            int u = prerequisite[0];
            int v = prerequisite[1];
            adj[v].push_back(u);
        }
        vector<bool> vis(numCourses);
        vector<bool> inrecursion(numCourses);
        stack<int> st;
        for(int i=0;i<adj.size();i++){
            if(!vis[i]){
                dfs(i , numCourses , adj , vis,st,inrecursion);
            }
        }
       
        vector<int> ans;
         if(hasCycle == true) return {};
        while(!st.empty()){
            int node = st.top();
            st.pop();
            ans.push_back(node);
        }
        return ans;
    }
};