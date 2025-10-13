// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1,hi  = n;
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(isBadVersion(mid)) hi  = mid; //if found then before mid all r bad versions so shrink hi to mid 
            else lo = mid+1;       //till mid version is good 
        }
        return lo;
    }
};