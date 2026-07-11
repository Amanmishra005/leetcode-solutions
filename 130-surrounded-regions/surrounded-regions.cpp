class Solution {
public:
    void dfs(vector<vector<char>>& board , int row, int col , vector<vector<int>>& vis){
        int m = board.size();
        int n = board[0].size();
        vis[row][col] = 1;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[]  = {0, -1, 0,1};
        for(int k = 0;k<4;k++){
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && board[nrow][ncol]=='O' && !vis[nrow][ncol]){
                dfs(board , nrow , ncol , vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m  = board.size();
        int n  = board[0].size();
        vector<vector<int>> vis(m , vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(board[i][j] == 'O' && !vis[i][j]){
                        dfs(board , i , j , vis);
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(!vis[i][j] && board[i][j]== 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};