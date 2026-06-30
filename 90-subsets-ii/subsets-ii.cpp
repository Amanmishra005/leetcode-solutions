class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> subsetii;
        dfs(nums,0, res , subsetii);
        return res;
    }
    void dfs(const vector<int>& nums , int i , vector<vector<int>>& res  , vector<int>& subsetii){
        if(i>=nums.size()){
            res.push_back(subsetii);
            return;
        }
        subsetii.push_back(nums[i]);
        dfs(nums , i+1, res , subsetii);
        subsetii.pop_back();
        int idx = i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]) idx++;
        dfs(nums, idx, res , subsetii);
    }
};