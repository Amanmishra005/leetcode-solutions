class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int product =  1;
        int subarray = 0;
        int i = 0 , j = 0;
         if (k <= 1) return 0;
        while(j < n){
            product *= nums[j];
            
            while(product >= k){
                product /= nums[i];
                
                i++;
            }
    subarray +=  j-i+1;         // += number of such contigous subarrays
            j++;
        }
        return subarray;

    }
};