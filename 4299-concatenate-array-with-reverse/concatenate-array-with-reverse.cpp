class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> arr1 = nums;
        reverse(arr1.begin(),arr1.end());
        nums.insert(nums.end(),arr1.begin(),arr1.end());
        return nums;
    }
};