class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int> , int>> q; //{row,col} , time
        int vis[m][n];
        int cntfresh = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1 ) cntfresh++;
            }
        }
        int totalTime = 0;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        int cnt = 0;
        while(q.size()!=0){
            int row =  q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && nrow<m && ncol >= 0 && ncol<n && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol} , time+1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
            totalTime = max(totalTime , time);
        }
        if(cnt != cntfresh) return -1; //all converted or not check 
        return totalTime;

    }
};