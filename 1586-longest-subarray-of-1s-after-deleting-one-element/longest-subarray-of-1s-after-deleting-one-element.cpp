class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;            // start of window
        int zeroCount = 0;    // how many zeros in current window
        int maxLen = 0;       // result

        for (int j = 0; j < n; j++) { // j = end of window
            if (nums[j] == 0) zeroCount++; // add nums[j] into window

            // shrink window if too many zeros
            while (zeroCount > 1) {
                if (nums[i] == 0) --zeroCount; // removing a zero → decrease count
                i++; // move start forward
            }

            // j - i = window_size - 1 (because we must delete one element)
            maxLen = max(maxLen, j - i);
        }

        return maxLen;
    }
};
