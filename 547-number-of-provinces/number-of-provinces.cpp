class Solution {
public:
    void bfs(int currnode , vector<vector<int>>& isConnected  , vector<bool>& vis){
        vis[currnode] = true;
         queue<int> q;
        q.push(currnode);
        while(!q.empty()){
            int node  = q.front();
            q.pop();
            for(int i  = 0 ;i<isConnected.size();i++){
                if(!vis[i] && isConnected[node][i]==1){
                    bfs(i , isConnected , vis);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
       
        vector<bool> vis(n,false);
        int count = 0 ;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                bfs(i , isConnected , vis);
            }
        }
        return count;
    }
};