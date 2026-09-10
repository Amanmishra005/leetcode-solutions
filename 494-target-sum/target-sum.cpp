class Solution {  //knapsack pattern 
public:

    int solve(vector<int>& nums , int sum , int n ,vector<vector<int>>& dp){
        
        if(n==0){
            if(sum==0) return 1;
            else return 0;
        }
        if(dp[sum][n] != -1) return dp[sum][n];
        if(nums[n-1] <= sum){
            return dp[sum][n] =  solve(nums , sum-nums[n-1] , n-1,dp) + solve(nums , sum , n-1,dp);
        }
        else{
            return dp[sum][n] = solve(nums , sum , n-1,dp);
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int array_sum = 0;
        for(auto x : nums){
            array_sum += x; 
        }
        if(abs(target) > array_sum) return 0;
        if((array_sum + target) % 2 != 0  ) return 0;

        int sum = (target +  array_sum )/ 2; //s1-s2 = target , s1+s2 = arraysum , add both equation remains s1(new target)
        
        vector<vector<int>> dp(sum +1 , vector<int>(n+1 , -1));
        // memset(dp , -1 , sizeof(dp));
        return solve(nums , sum,n,dp);
    }
};