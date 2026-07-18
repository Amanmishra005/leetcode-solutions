class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][0] == 1 || grid[m-1][n-1]==1)
            return -1;
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        q.push({0,0});
        vis[0][0] = 1;
        int level = 1;
                int delrow[] = {-1,-1,-1,0,0,1,1,1};
        int delcol[] = {-1,0,1,-1,1,-1,0,1};
        while(!q.empty()){
            int sz = q.size();
            while(sz--){            //inorder to process only the current level node at a time 
                auto currnode = q.front();
                q.pop();
                int x = currnode.first;
                int y = currnode.second;
                if(x==m-1 && y==n-1) return level;
                for(int i=0;i<8;i++){
                    int x_ = x + delrow[i];
                    int y_ = y + delcol[i];
                    if(x_ >= 0 && x_<m && y_>=0 && y_<n){
                        if(vis[x_][y_]==0 && grid[x_][y_]==0){
                            q.push({x_,y_});
                            vis[x_][y_] = 1;
                        }
                    }
                }
            }
            level++;
        }
        return -1;

    }
};