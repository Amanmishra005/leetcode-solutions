class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int cs = 0;
        for(int i=0;i<nums.size();i++){
            cs += nums[i];
            maxSum = max(maxSum , cs);
            if(cs < 0) cs =0;
        }
        return maxSum;
    }
};