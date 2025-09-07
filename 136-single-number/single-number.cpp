class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int result = 0;   
        for (int i = 0; i < n; i++) {
            result = result ^ nums[i];   //0^0 = 0 || 1^1 = 0 comparing with result i.e 0
        }                                 //1^0 = 0 || 0^1 = 1

        return result;
    }
};
