class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n  = cost.size();
        if(n==1) return cost[0];
        vector<int> t(n+1 , 0);
        t[0] = 0;
        t[1] = 0;
        for(int i = 2;i<=n;i++){
            int onestep = t[i-1] + cost[i-1];
            int twostep = t[i-2]  + cost[i-2];
           t[i] =  min(onestep , twostep);
        }
        return t[n];
    }
};