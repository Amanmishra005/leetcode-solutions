class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> vis(m , vector<int>(n,0));
        vector<vector<int>> dist(m , vector<int>(n,0));
        queue<pair<pair<int , int> , int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int nearest = q.front().second;
            q.pop();
             dist[row][col] = nearest; ///
            for(int k=0;k<4;k++){
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==0){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow , ncol},nearest+1});
                }
            }
        }
                   
        return dist;
    }
};