class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int  m =  grid.size();
        int n = grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1]==1) return -1;
        vector<vector<int>> result(m , vector<int>(n , INT_MAX));
        priority_queue<pair<int, pair<int,int>> , vector<pair<int, pair<int,int>>> , greater<pair<int , pair<int,int>>>> pq;
        pq.push({0, {0,0}});
        result[0][0] = 0;
        int delrow[] = {-1,-1,-1,0,0,1,1,1};
        int delcol[] = {-1,0,1,-1,1,-1,0,1};
        while(!pq.empty()){
            int d = pq.top().first;
            pair<int,int> node = pq.top().second;
            int x =  node.first;
            int y = node.second;
            pq.pop();
            for(int i=0;i<8;i++){
                int x_ = x + delrow[i];
                int y_ = y + delcol[i];
                int dist = 1;
                if(x_ >= 0 && x_ < m && y_>= 0 && y_<n && grid[x_][y_]==0  && d+ dist< result[x_][y_]){
                    pq.push({d+dist , {x_ , y_}});
                    result[x_][y_] = d+dist;
                }
            }
            

        }
        if(result[m-1][n-1]== INT_MAX) return -1;
        return result[m-1][n-1] + 1;
    }
};