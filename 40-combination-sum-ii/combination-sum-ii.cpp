class Solution {
public:

    void combinationII(vector<int>& candidates , int idx , int target , vector<vector<int>>& ans , vector<int>& comb){
        if(target==0){
                 ans.push_back(comb);       
            return;
        }
        if(idx==candidates.size() || target <0) return;
         comb.push_back(candidates[idx]);
        combinationII(candidates ,  idx +1 , target-candidates[idx], ans , comb);
        comb.pop_back();
        int next  = idx + 1;
        while(next < candidates.size() && candidates[next]==candidates[next-1]){
            next++;
        }
        combinationII(candidates , next , target , ans, comb);
       
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;
        combinationII(candidates , 0 , target , ans , comb);
        return ans;


    }
};