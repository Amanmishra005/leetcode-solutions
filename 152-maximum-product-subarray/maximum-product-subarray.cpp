class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int leftprod = 1;
        int rightprod = 1;
        int result = nums[0];
        //calculate and compare left,right,result;
        for(int i=0;i<n;i++){
            if(leftprod==0){
                leftprod = 1;
            }
            if(rightprod==0){
                rightprod = 1;
            }

            leftprod *= nums[i];
            rightprod *= nums[n-1-i];
            
            result = max(result , max(leftprod , rightprod));
        }
        return result;
    }
};