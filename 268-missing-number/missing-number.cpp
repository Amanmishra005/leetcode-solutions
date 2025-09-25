class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
      int lo = 0;
      int hi = nums.size();
      while(lo <hi){
        int mid = lo + (hi-lo)/2;
        if(nums[mid]>mid){
            hi = mid;
        }
        else{
            lo = mid+1;
        }
      }
      return lo;
    }
};