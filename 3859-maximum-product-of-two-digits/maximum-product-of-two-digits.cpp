class Solution {
public:
    int maxProduct(int n) {
        int fdigit = 0 ;
        int sdigit  = 0;
        while(n>0){
            int digit = n %10;
            if(digit > fdigit){
                sdigit = fdigit;
                fdigit = digit;
            }else if(digit > sdigit){
                sdigit = digit;
            }
            n /= 10;
        }
        return fdigit * sdigit; 

    }
};