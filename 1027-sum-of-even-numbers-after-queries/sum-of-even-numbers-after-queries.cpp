class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        int evensum =  0;
        for(auto& it : nums){
            if(it%2==0){
                evensum += it;
            }
        }
        vector<int> result;
        for(auto& q : queries){
            int val = q[0];
            int indx = q[1];
            if(nums[indx] % 2 ==0){
                evensum -= nums[indx];      //clear the that precomputed num since it will change 
            }
            nums[indx] += val;       //value changed
            if(nums[indx] %2 == 0){
                evensum += nums[indx];           //after computing again push 
               
            }
             result.push_back(evensum);
        }
        return result;
    }
};