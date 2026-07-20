class Solution {
public:
    void reverse(vector<vector<int>>& grid , int left , int right , int col){
        while(left < right){
            swap(grid[left/col][left%col] , grid[right/col][right%col]);    //interchanging element 
            left++;
            right--;
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row=grid.size();
        int col = grid[0].size();
        int n = row*col;
        k %= n;
        if(k==0) return grid;
        reverse(grid , 0 , n-1 , col);
        reverse(grid , 0 , k-1,col);
        reverse(grid , k , n-1,col);
        return grid;
    }
};