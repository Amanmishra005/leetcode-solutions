class Solution {
public:
    bool bfsbipart(int currnode , vector<vector<int>>& graph , vector<int>& color , int currcolor){
        color[currnode] = currcolor;
        queue<int> q;
        q.push(currnode);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &it:graph[node]){
                if(color[it]==color[node]) return false;
                if(color[it]==-1){
                    color[it] = 1 - color[node];
                    q.push(it);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1 && bfsbipart(i , graph , color , 1)==false) return false;
        }
        return true;
    }
};