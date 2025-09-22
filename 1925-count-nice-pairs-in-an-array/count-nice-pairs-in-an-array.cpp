class Solution {
public:
int reverse(int n){
    int rev = 0;
    while(n>0){
        int dig = n%10;
        rev = rev*10 + dig;
        n /=10;
    }
    return rev;
}
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            nums[i] -= reverse(nums[i]);
        }
        for(int i=0;i<n;i++){
            if(m.find(nums[i])!=m.end()){
                count = count % 1000000007; //handles large output given condition 
                count += m[nums[i]];
                m[nums[i]]++;
            }
        else  m[nums[i]]++;    
    }
    return count%1000000007;
    }
};