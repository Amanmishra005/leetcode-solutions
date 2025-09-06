class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i=0;
         if(n<1) return;

        for(int j=0;j<n;j++){ //j=0 to check if array has only one element
            if(nums[j]!=0) {
                nums[i] = nums[j];
                i++;
            }
            
        }
        while(i<n){
            nums[i] =0;
            i++;
        }
    }
};