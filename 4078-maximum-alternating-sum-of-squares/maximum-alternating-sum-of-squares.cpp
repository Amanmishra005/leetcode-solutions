class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
       vector<int> vecabs(n,0);
       for(int i=0;i<n;i++){
        vecabs[i] = nums[i]*nums[i];
       }
       sort(vecabs.begin(),vecabs.end());
       long long ans = 0;
       for(int i=0;i<n/2;i++){
        ans -= vecabs[i];
       }
       for(int i=n/2;i<n;i++){
        ans += vecabs[i];
       }
       return ans;
    }
};