class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols= matrix[0].size();
        int lo = 0;
        int hi = rows*cols-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;                   //mid is the idx we are checking on 
            int val = matrix[mid/cols][mid%cols];       //matrix[i][j];
            if(val == target) return true;
            else if(val<target) lo = mid+1;
            else hi = mid-1;
        }
        return false;
    }
};