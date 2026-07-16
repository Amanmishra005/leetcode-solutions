class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void   Union(int x , int y){
        int parent_x = find(x);
        int parent_y = find(y);
        if(parent_x == parent_y) return;
        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }
        else if(rank[parent_x] < rank[parent_y] ){
            parent[parent_x] = parent_y;
        }else{
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 1;
        }
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            Union(u,v);
        }
        unordered_map<int , int> mp;
        for(int i=0;i<n;i++){
            int leader = find(i);
            mp[leader]++;
        }
        long long result = 0;
        long long remainingnodes = n;
        for(auto &m : mp){
            long long size =  m.second;
            result += size * (remainingnodes - size);
            remainingnodes -= size;
        }
        return result;
    }
};