class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int cand = nums[n/2];
        int count = 0;
        for(int s : nums){
            if(s == cand) count++;
        }
        if(count > n/2) return cand;
        return -1;

    }
};