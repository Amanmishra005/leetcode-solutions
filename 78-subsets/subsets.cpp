class Solution {
public:
    vector<vector<int>> result;
    void solve(int index , vector<int>& nums , vector<int>& sub){
        if(index >= nums.size()){
            result.push_back(sub);
            return;
        }
        sub.push_back(nums[index]);
        solve(index +1 , nums , sub);
        sub.pop_back();
        solve(index +1 , nums , sub);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;

      

        solve(0 ,  nums , sub);
        return result;
    }
};