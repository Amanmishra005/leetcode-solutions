class Solution {
public:
    void dfs(int row, int col,
             vector<vector<int>>& vis,
             vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col] = 1;

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

     

            for(int i=0;i<4;i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<m &&
                   ncol>=0 && ncol<n &&
                   grid[nrow][ncol]=='1' &&
                   !vis[nrow][ncol]) {

                  dfs(nrow,ncol,vis,grid);
                }
            }
        
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n,0));

        int cnt = 0;

        for(int row=0; row<m; row++) {
            for(int col=0; col<n; col++) {

                if(!vis[row][col] && grid[row][col]=='1') {
                    cnt++;
                    dfs(row,col,vis,grid);
                }
            }
        }

        return cnt;
    }
};