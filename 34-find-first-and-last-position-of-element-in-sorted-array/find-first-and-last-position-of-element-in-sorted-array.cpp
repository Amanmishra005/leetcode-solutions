class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n =  nums.size();
        int lo = 0,hi = n-1;
        int first = -1;
        int last = -1;
        while(lo<=hi){
            int mid =  lo + (hi-lo)/2;
            if(nums[mid]==target){
                first = mid;            //store the first occur
                hi = mid-1;             //search for the first occur if exist 
            }else if(nums[mid] < target) lo = mid+1;
            else hi = mid-1;
        }
        lo = 0;hi  = n-1;
         while(lo<=hi){
            int mid =  lo + (hi-lo)/2;
            if(nums[mid]==target){
                last = mid;
                lo = mid+1;              //search for the last occur if exist on the right side  
            }else if(nums[mid] < target) lo = mid+1;
            else hi = mid-1;
        }
        return{first,last};     //vector containing first and last occurence 

    }
};