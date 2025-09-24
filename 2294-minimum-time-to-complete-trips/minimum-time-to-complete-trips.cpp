class Solution {
public:
    bool check(long long mid,vector<int>& time,int totalTrips){
        long long trips = 0;
        int n = time.size();
        for(int i = 0;i<n;i++){
            trips += (long long)mid/ time[i];  //mid is the time that we r testing on that will be mini & sufficient complete the totalTrips 
        }
        if(trips<totalTrips) return false;
        else return true;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        int max = -1;
        for(int i=0;i<n;i++){
            if(max < time[i]) max = time[i];
        }
        long long lo =1;
        long long hi = (long long)max * (long long)totalTrips;  //cant't go out of it 
        long long ans = -1;
        while(lo<=hi){
            long long mid = lo + (hi-lo)/2;
            if(check(mid,time,totalTrips)==true){
               ans =mid;        //time taken to complete the totalTrips 
               hi = mid-1; 
            }
            else lo = mid+1;
        }
        return ans;     //minimum time taken to complete the totalTrips 
    }
};