class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int result = 0;                 //different element will return on comparing
        for (int i = 0; i < n; i++) {
            result = result ^ nums[i];   //0^0 = 0 || 1^1 = 0 comparing with result i.e 0
        }                                 //1^0 = 0 || 0^1 = 1
                                        //(1 ^ 1) ^ (2 ^ 2) ^ 4
        return result;
    }
};
