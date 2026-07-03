class Solution {
public:
set<vector<int>> s;
void combinationSum(vector<int>& candidates , int idx, int target , vector<vector<int>>& ans , vector<int>& comb){
    if(idx == candidates.size() || target <0) return;
    if(target==0){
        if(s.find(comb) == s.end()){
            ans.push_back(comb);
            s.insert(comb);
            
        }
        return;
    }
    comb.push_back(candidates[idx]);
    combinationSum(candidates , idx+1 , target - candidates[idx], ans,comb); //single time do
    combinationSum(candidates , idx , target - candidates[idx] , ans , comb); //multiple time so idx only 
    comb.pop_back(); //dont include
    combinationSum(candidates , idx +1 ,target , ans , comb);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        combinationSum(candidates , 0 , target , ans , comb);
        return ans;
    }
};