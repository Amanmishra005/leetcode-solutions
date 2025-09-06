class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        int n = nums.size();
        int k=0;
       for(int i=0;i<n;i++){
        if(nums[i]!=val) {
            nums[k] = nums[i];
            k++;
        }
       }
       return k;
    }
};