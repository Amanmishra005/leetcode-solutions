class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n =  nums.size();
       int i=1;
       while(i<n && nums[i] > nums[i-1]) i++;
       if(i==1) return false;
       int start = i;
       while(i<n && nums[i] < nums[i-1]) i++;
       if(i==start) return false;
       start = i;
       while(i<n && nums[i] > nums[i-1]) i++;
       while(start==i) return false;

       return i==n;

    }
};