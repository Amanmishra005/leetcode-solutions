class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        bool onlyzero = true;
        for(int x : nums){
            ans = ans ^ x;
            if(x!=0) onlyzero = false;
        }
        if(onlyzero) return 0;
        if(ans == 0) return n-1;
        else return n;
    }
};