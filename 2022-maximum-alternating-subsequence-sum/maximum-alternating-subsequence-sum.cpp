class Solution {
public:
    int n;
    long long t[100001][2];
    long long solve(int idx , vector<int>& nums , bool flag){
        if(idx>=n) return 0;

        long long val = nums[idx];
        if(t[idx][flag]!=-1) return t[idx][flag];
        if(flag ==false){
            val = -val;
        } 
        long long skip = solve(idx +1 , nums , flag);
        long long take = solve(idx+1 , nums , !flag) + val;
        return t[idx][flag] = max(skip,take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
         n = nums.size();
         memset(t , -1, sizeof(t));
        return solve(0 , nums , true);
    }
};