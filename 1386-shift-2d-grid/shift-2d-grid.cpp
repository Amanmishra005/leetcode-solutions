class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        int n = row*col;
        k = k%n;
        if(k==0) return grid;
        vector<vector<int>> ans(row , vector<int>(col , 0));
        for(int i=0;i<n;i++){
            int val = grid[i/col][i%col];
            int newidx = (i + k) % n;
            int nrow = newidx / col;
            int ncol = newidx % col;
            ans[nrow][ncol] = val;
        }
        return ans;
    }
};