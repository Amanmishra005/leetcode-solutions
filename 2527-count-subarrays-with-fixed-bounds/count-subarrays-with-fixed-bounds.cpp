class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int minindx = -1;
        int maxindx = -1;
        int greater = -1;
        long long ans = 0;
        for(int i=0;i<n;i++){
            if(nums[i] < minK || nums[i] > maxK){
                greater = i;
            }
            if(nums[i] == minK){
                minindx = i;
            }
            if(nums[i]== maxK){
                maxindx = i;
            }
            long long smaller = min(minindx , maxindx);
            long long temp = smaller - greater;
            if(temp < 0 ) ans += 0;
            else ans += temp;
        }
        return ans;
    }
};