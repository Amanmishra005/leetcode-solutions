class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &time : times){
            int u = time[0];
            int v = time[1];
            int wt = time[2];
            adj[u].push_back({v , wt});
            
        }
        vector<int> result(n+1 , INT_MAX);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        result[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if( d > result[node]) continue;
            for(auto it  : adj[node]){
                int adjnode = it.first;
                int dist = it.second;
                if(d + dist < result[adjnode]){
                    result[adjnode] = d+dist;
                    pq.push({d+dist , adjnode});
                }
            }
        }
        int ans = INT_MIN;
        for(int  i =1;i<=n;i++){
            if(result[i]==INT_MAX) return -1;
            ans = max(result[i], ans);
        }
        return ans;
    }
};