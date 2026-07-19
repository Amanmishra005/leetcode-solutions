class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> t(n+1 , 0);
        t[1] = nums[0];
        for(int i=1;i<=n-1;i++){
            int steal = nums[i-1] + (i-2>=0 ? t[i-2] : 0);
            int skip = t[i-1];
            t[i] = max(steal , skip);
        }
        int withoutlast = t[n-1];
        t.clear();
        
        t[1]  = 0; //skipped first house
        for(int i=2;i<=n;i++){
            int steal = nums[i-1] + t[i-2];
            int skip = t[i-1];
           t[i] = max(steal , skip);
        }
        int withlast = t[n];
        return max(withoutlast , withlast);
    }
};