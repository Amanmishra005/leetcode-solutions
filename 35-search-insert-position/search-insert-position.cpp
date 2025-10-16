class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int n = arr.size();
        int lo = 0;
        int hi= n-1;
        while(lo<=hi){
            int mid = (hi+lo)/2;
            if(arr[mid]==target) return mid;
            else if(arr[mid]>target) hi = mid-1;
            else lo= mid+1;
        }
        return lo;  //insert here
    }
};