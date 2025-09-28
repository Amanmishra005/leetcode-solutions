class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int  n = nums.size();
      int i = 0;
      int j = 0;
        int minLen = INT_MAX;
        int len;
        int sum = 0;
        while(j<n){
            sum += nums[j];
            while(sum>=target){
                len = j-i+1;
                minLen = min(minLen,len);
                sum -=nums[i];  //shrink window from left to chek for others
                i++;
            }
            j++;
        }
        if (minLen==INT_MAX) return 0;  //if any valid subarray not found then return 
        return minLen;                  
    }
};