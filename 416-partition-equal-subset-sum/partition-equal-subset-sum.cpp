class Solution {
public:
// vector<int>& nums ;

    int dp[1001][10001];
    
    bool solve(vector<int>& nums , int n ,int target){
        if(target==0) return true;
        if(n==0) return false;
        if(dp[n][target]!=-1) return dp[n][target];
       if(nums[n-1] <= target ){
        return dp[n][target] = solve(nums , n - 1 , target - nums[n-1]) || solve(nums , n-1, target); //make choice either take or not 
       }else{ //nums[n-1] > target
            return dp[n][target] = solve(nums , n-1 , target);
       }
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        memset(dp , -1 ,sizeof(dp));
        for(auto x : nums){
            sum += x;
        }
        if(sum %2 != 0) return false;
         int target = sum/2;
        return solve(nums , n , target);
    }
};