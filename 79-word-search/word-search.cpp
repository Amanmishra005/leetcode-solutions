class Solution {
public:
    int m , n;
    bool backt(vector<vector<char>>& board , int i , int j , int idx , string& word){
        if(idx==word.length()) return true;

        if(i<0 || j<0 || i>=m || j>=n || board[i][j]=='$') return false;

        if(board[i][j]!= word[idx]) return false;

        char temp = board[i][j];
        board[i][j] = '$';
        int delrow[] = {1, 0 , -1 , 0};
        int delcol[] = {0, -1 , 0, 1};
        for(int k=0;k<4;k++){
            int nrow = i + delrow[k];
            int ncol = j + delcol[k];
            if(backt(board , nrow , ncol , idx+1 , word)){
                board[i][j] = temp;
                return true;
            }
        } 
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
         m  =board.size();
         n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j] == word[0] && backt(board , i , j , 0 , word)) return true;
            }
        }
        return false;
    }
};