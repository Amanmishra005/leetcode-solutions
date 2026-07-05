class Solution {
public:
bool places(vector<string>& qp , int row , int n , int col){
    for(int i=0;i<n;i++){
        if(qp[row][i]=='Q') return false;
    }
    for(int i=0;i<n;i++){
        if(qp[i][col]=='Q') return false;
    }
    for(int i = row , j = col ; i>=0 && j>=0; i-- , j--){
        if(qp[i][j]=='Q') return false;
    }
    for(int i=row , j = col ; i>=0 && j<n; i-- , j++){
        if(qp[i][j]=='Q') return false;
    }
    return true;

}
    void nqueens(vector<string>& qp , int row  , int  n , vector<vector<string>>& q){
        if(row== n){
            q.push_back(qp);
            return;
        }
        for(int i=0;i<n;i++){
            if(places(qp,row  , n , i)){
                qp[row][i] = 'Q';
                nqueens(qp , row + 1 , n , q);
                qp[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> q;
        vector<string> qp(n , string(n , '.'));
        nqueens(qp , 0 , n , q);
        return q;
    }
};