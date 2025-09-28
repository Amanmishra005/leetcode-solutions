class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;            // start of window
        int zeroCount = 0;    // how many zeros in current window
        int maxLen = 0;      

        for (int j = 0; j < n; j++) { 
            if (nums[j] == 0) zeroCount++; // add nums[j] into window

           //if more than one zero in the window then remove 
            while (zeroCount > 1) {
                if (nums[i] == 0) --zeroCount; // removing a zero → decrease count 
                i++; // shift
            }
            maxLen = max(maxLen, j - i);
        }

        return maxLen;
    }
};
