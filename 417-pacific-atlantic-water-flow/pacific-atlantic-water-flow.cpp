class Solution {
public:
    void dfs(vector<vector<int>>& heights , int row , int col , int prevcell , vector<vector<bool>>& visited ){
        int m = heights.size();
        int n = heights[0].size();
        if(row<0 || row>=m || col<0 || col>=n || heights[row][col] < prevcell  || visited[row][col]) return;
        visited[row][col] = true;
        int delrow[] = {-1, 0 , 1 , 0};
        int delcol[] = {0,-1,0,1};
        for(int k = 0 ;k<4;k++){
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];
            dfs(heights , nrow , ncol , heights[row][col] , visited);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m , vector<bool>(n , false));
        vector<vector<bool>> atlantic(m , vector<bool>(n , false));
        vector<vector<int>> result;
        for(int j = 0;j<n;j++){
            dfs(heights , 0 , j ,INT_MIN ,pacific);
            dfs(heights , m-1 , j ,INT_MIN, atlantic);                   //first row pacific last row atlantic 
        }
        for(int i = 0;i<m;i++){
            dfs(heights, i , 0 ,INT_MIN ,pacific);
            dfs(heights , i , n-1 ,INT_MIN, atlantic);      //first col and last col
        }
        for(int i = 0 ;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};