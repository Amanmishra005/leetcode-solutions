class Solution {
public:
    void dfs(int row , int col,vector<vector<int>>& ans ,vector<vector<int>>& image,int newColor , int delrow[] , int delcol[] , int iniColor){
        int m = image.size();
        int n = image[0].size();
        ans[row][col] = newColor;
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol < n && image[nrow][ncol]==iniColor && ans[nrow][ncol] != newColor){
                dfs(nrow , ncol, ans, image,newColor , delrow , delcol , iniColor );
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        dfs(sr , sc ,ans, image , color , delrow , delcol , iniColor);
        return ans;
    }
};