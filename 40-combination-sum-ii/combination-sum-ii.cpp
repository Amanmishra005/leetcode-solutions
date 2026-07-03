class Solution {
public:

    void combinationII(vector<int>& candidates , int idx , int target , vector<vector<int>>& ans , vector<int>& comb){
        if(target==0){
                 ans.push_back(comb);       
            return;
        }
        if(idx==candidates.size() || target <0) return;
         for(int i = idx ; i<candidates.size();i++){
            if(i > idx && candidates[i]==candidates[i-1]){
                continue;
            }
             comb.push_back(candidates[i]);
        combinationII(candidates ,  i +1 , target-candidates[i], ans , comb);
        comb.pop_back();
         }
       
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;
        combinationII(candidates , 0 , target , ans , comb);
        return ans;


    }
};