#define ll long long
class Solution {
public:
    long long countCommas(long long n) {
        ll result = 0;
        ll comma = 1;
        ll lower = 1000;
        while(lower <= n){
            ll upper = lower*1000 -1;
            if(upper > n) upper = n;
            ll numrange = upper - lower +1;
            result += (numrange * comma);

            lower *= 1000; //next range lower
            comma++;        //next range comma count

        }
        return result;
    }
};