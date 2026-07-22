class Solution {
public:
     int dp[2501][2501];
    int solve(vector<int>& nums , int curridx , int prevele){
        if(curridx >= nums.size()) return 0;
       if(prevele != -1 && dp[curridx][prevele]!=-1) return dp[curridx][prevele];

        int take = 0;
        if(prevele==-1 || nums[prevele]<nums[curridx]){
            take = 1 + solve(nums , curridx + 1 , curridx );
        }
        int skip = solve(nums , curridx + 1 , prevele);
        if(prevele != -1) dp[curridx][prevele] = max(take , skip);;
        return max(take , skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memset(dp , -1 , sizeof(dp));
        return solve(nums , 0 , -1);
    }
};