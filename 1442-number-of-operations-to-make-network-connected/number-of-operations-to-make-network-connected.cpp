class Solution {
public:
vector<int> parent;
vector<int> rank;
int find(int x){
    if(parent[x] == x ) return x;
    return parent[x] = find(parent[x]);
}
void Union(int x , int y){
    int parent_x = find(x);
    int parent_y = find(y);
    if(parent_x == parent_y) return;
    if(rank[parent_x] > rank[parent_y]){
        parent[parent_y] = parent_x;
    }
    else if(rank[parent_x] < rank[parent_y]){
        parent[parent_x] = parent_y;
    }else{
        parent[parent_y] = parent_x;
        rank[parent_x]++;
    }
}
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 1;
        }
        int component=  n;          //in start one element group itself only
        for(auto &node : connections){
            int u = node[0];
            int v = node[1];
            if(find(u) != find(v)){         //if they dont have same parent then do so 
                Union(u , v);
                component--;            //groups becoming larger
            }      
        }
        return component - 1;
        
    }
};