class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m =  grid.size();
        int n =  grid[0].size();
        queue<pair<pair<int,int> , int>> q;
          int vis[m][n];
           int cntfresh = 0;
           for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                    
                }else {
                    vis[i][j] = 0;
                    
                }
                if(grid[i][j]==1) cntfresh++;
            }
           }
           int tm = 0;
           int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};
            int fresh = 0;
           while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int rottentime = q.front().second;
            tm  = max(tm , rottentime);
            q.pop();
            for(int k = 0;k<4;k++){
                int nrow = r  + delrow[k];
                int ncol = c + delcol[k];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
                    fresh++;
                    q.push({{nrow,ncol} , rottentime + 1});
                    vis[nrow][ncol] = 2;
                }
            }
            tm  = max(tm , rottentime);
           }
           if(cntfresh != fresh) return -1;
           return tm;
    }
    
};