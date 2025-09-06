class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        // prev greatest element array (left max)
        vector<int> prev(n);
        prev[0] = -1;
        int maxLeft = height[0]; //max height from left till now
        for (int i = 1; i < n; i++) {
            prev[i] = maxLeft;
            maxLeft = max(maxLeft, height[i]);
        }

        // next greatest element array (right max)
        vector<int> next(n);
        next[n - 1] = -1; 
        int maxRight = height[n - 1];   //max height from right till now
        for (int i = n - 2; i >= 0; i--) {
            next[i] = maxRight;
            maxRight = max(maxRight, height[i]);
        }

        // calculating trapped water
        int water = 0;
        for (int i = 1; i < n - 1; i++) {
            int minHeight = min(prev[i], next[i]);
            if (height[i] < minHeight) {
                water += minHeight - height[i];
            }
        }

        return water;
    }
};
