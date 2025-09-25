class Solution {
public:
    int gcd(int a,int b){
        if(a==0) return b;
        return gcd(b%a,a);
    }
    int gcdOfOddEvenSums(int n) {
        int a = n*n;
        int b = n*(n+1);
        return gcd(a,b);
    }
};