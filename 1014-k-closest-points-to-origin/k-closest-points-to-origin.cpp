class Solution {
public:
typedef pair<int,vector<int>> piv;  //vector is for coordinates i.e in pairs
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        priority_queue<piv> max; //
        for(auto v: arr){       //catching vector here 
            int x = v[0] , y = v[1];        //coordinate x-y
            int dis = x*x + y*y;
            max.push({dis,v});  //distance and coordinates from  origin point i.e the vector v itself
            if(max.size()>k) max.pop();
        }
        vector<vector<int>> ans;
        while(!max.empty()){
            ans.push_back( max.top().second);   //return coordinate pairs
            max.pop();
        }
        return ans;
    }
};