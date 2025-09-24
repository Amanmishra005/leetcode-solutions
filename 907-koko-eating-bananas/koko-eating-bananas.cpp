class Solution {
public:
    bool check(int speed,vector<int>& piles,int h){
        int count = 0;      //total num of hours taken to eat bananas 
        int n = piles.size();
        for(int i =0;i<n;i++){
            if(count>h) return false;   //to avoid long long i.e hours become so big 
            if(speed>=piles[i]) count++;    //can eat in 1 hour
            else if(piles[i]%speed==0) count += piles[i]/speed; //exactly divisible
            else count += piles[i]/speed + 1; //add 1 extra to eat remaining
        }
        if(count>h) return false;
        else return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int max = INT_MIN;
        for(int i =0;i<n;i++){
            if(max < piles[i]) max = piles[i];
        }
        int lo = 1;
        int hi = max;
        int ans = -1;           //let say 
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,piles,h)==true){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;         //the optimal minspeed by which banana can be eaten in a given time h
    }
};