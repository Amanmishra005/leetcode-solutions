class Solution {
public:
    int dfs(vector<vector<int>>& grid , int row, int col , vector<vector<int>>& vis){
        int m = grid.size();
        int n = grid[0].size();
        vis[row][col] = 1;
        int area = 1;
        int delrow[] = {-1, 0 ,1,0};
        int delcol[] = {0,-1, 0,1};
        for(int k=0;k<4;k++){
            int nrow = row  + delrow[k];
            int ncol = col + delcol[k];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                area += dfs(grid , nrow , ncol , vis);
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int  m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m , vector<int>(n,0));
        int maxArea = 0;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1 && !vis[row][col]){
                    int  gotnewArea= dfs(grid , row, col , vis);
                    maxArea = max(maxArea , gotnewArea);
                }
            }
        }
        return maxArea;
    }
};