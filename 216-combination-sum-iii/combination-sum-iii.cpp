class Solution {
public:
    void combination(vector<vector<int>>& ans,vector<int> v,int k,int n,int start){
        if(v.size()==k && n==0){
            ans.push_back(v);
            return;
        }
        if(v.size()>k || n<0 ) return;
        for(int i=start;i<=9;i++){
            v.push_back(i);
            combination(ans,v,k,n-i,i+1);       //finding all valid cominations
            v.pop_back();       //if valid combination not found clean the vector v for next search
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        combination(ans,v,k,n,1);
        return ans;
    }
};