class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        for(int i =0;i<n;i++){
            int start = nums[i] % n;
            int index = (i +  start + n) % n;
            arr[i] = nums[index];
        }
        return arr;
    }
};