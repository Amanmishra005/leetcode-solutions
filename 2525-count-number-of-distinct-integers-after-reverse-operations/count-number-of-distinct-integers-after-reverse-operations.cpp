class Solution {
public:
int reverseNum(int n){
    int rev =0;
    while(n>0){
    int digit = n%10;
    rev = rev*10 + digit;
    n /=10;
    }
    return rev;
}
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int x: nums){
            int revN = reverseNum(x);
            s.insert(x);    //original numbers
            s.insert(revN); //reverse number insert
        }
        return s.size();
    }
};