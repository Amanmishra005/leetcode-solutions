class Solution {
public:
    bool check(int mid,vector<int>& weights,int days){
        int n = weights.size();
        int m = mid;            //max capacity it can hold in single day 
        int count = 1;          //days we are counting on the basis of mid taken 
        for(int i=0;i<n;i++){
            if(m>=weights[i]){
                m -= weights[i];        // put this package in current ship
            }
            else{
                count++;        //need one more day 
                m = mid ;       // reset ship capacity next day 
                m -= weights[i];    // load current package into the new ship 
            }
        }
        if(count> days) return false;
        else return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int max = INT_MIN;
        int sum = 0;
        for(int i=0;i<n;i++){
            if(max < weights[i]) max = weights[i];
            sum += weights[i];
        }
        int lo = max;
        int hi = sum;
        int minCapacity =  -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,weights,days)){    //default true else false 
                minCapacity = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return minCapacity;
    }
};