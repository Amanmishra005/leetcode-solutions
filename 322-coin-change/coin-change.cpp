class Solution {
public:
       vector<int> dp;
       int solve(vector<int>& coins,int amount){
        if(amount==0) return 0;
        if(dp[amount] != -2) return dp[amount];
        int result = INT_MAX;
        for(int coin : coins){
            if(amount - coin < 0) continue;
            int sub = solve(coins,amount - coin);
            if(sub!= -1) result = min(result,sub);
        }
        if(result==INT_MAX) return dp[amount] = -1;
        return dp[amount] = 1+ result;
       }
    int coinChange(vector<int>& coins, int amount) {
       dp.resize(amount + 1 , -2);
       return solve(coins,amount);
    }
};