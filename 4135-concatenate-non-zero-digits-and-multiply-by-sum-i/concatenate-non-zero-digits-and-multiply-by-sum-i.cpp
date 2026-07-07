class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        int sum = 0;
        long  long ans = 0;
        for( char c : s){
            if(c!='0'){
                int digit = c - '0';
                ans = ans * 10 + digit;
                sum += digit;
            }
        }
        return sum * ans;
    }
};