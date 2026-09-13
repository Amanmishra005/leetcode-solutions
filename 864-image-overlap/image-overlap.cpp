class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int  n = img1.size();
        vector<pair<int,int>> a,b;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1) a.push_back({i,j});
                if(img2[i][j]==1) b.push_back({i,j});
            }
        }
        int ans = 0;
        map<pair<int,int>,int> mp;
        for(auto [x1,y1] : a){
            for(auto [x2,y2] : b){
                int x_diff = x2-x1;
                int y_diff = y2-y1;
                mp[{x_diff , y_diff}]++;
                ans = max(ans , mp[{x_diff , y_diff}]);
            }
        }
        return ans;
    }
};