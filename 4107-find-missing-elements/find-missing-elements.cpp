class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        sort(nums.begin() , nums.end());
        for(int i=0;i<n-1;i++){
           for(int j = nums[i] + 1;j < nums[i+1];j++){ //2 , 5 -----> 3  < 5 
            res.push_back(j);
           }
        }
        return res;
    }
};