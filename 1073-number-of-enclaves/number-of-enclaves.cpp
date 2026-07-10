class Solution {
public:
void dfs(int row , int col , vector<vector<int>>& grid , vector<vector<int>>& vis){
    int m = grid.size();
    int n = grid[0].size();
    vis[row][col] = 1;
    int delrow[] = {-1 , 0 , 1, 0};
    int delcol[] = {0,-1, 0,1};
    for(int j = 0;j<4;j++){
        int nrow = row + delrow[j];
        int ncol = col +delcol[j];
        if(nrow>=0 && nrow<m && ncol>= 0 && ncol<n && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
            dfs(nrow , ncol , grid, vis);
        }
    }
}
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m , vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(grid[i][j]==1 && vis[i][j]==0){
                        dfs(i , j , grid , vis);
                    }
                    
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};