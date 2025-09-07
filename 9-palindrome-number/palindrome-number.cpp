class Solution {
public:
    bool isPalindrome(int x) {
        int digit;
        long long reversed = 0;
        int original = x;
        if(x<0) return false;
        while(x>0){
            digit = x%10;
            reversed = reversed*10 + digit;
            x /=10;
        }
        if(original == reversed){
            return true;
        }
        else{
            return false;
        }
    }
};