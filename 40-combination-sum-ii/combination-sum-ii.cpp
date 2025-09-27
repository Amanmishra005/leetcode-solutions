class Solution {
public:
    void combination(vector<vector<int>>& ans,vector<int>& candidates,vector<int> v, int target,int idx){
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(target<0) return;
        for(int i=idx;i<candidates.size();i++){ //target>0
            if( i>idx && candidates[i] == candidates[i-1]) continue;    //duplicates skip
            v.push_back(candidates[i]);
            combination(ans,candidates,v,target-candidates[i],i+1); //i+1 only one time use each ele
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        combination(ans,candidates,v,target,0);
        return ans;
    }
};