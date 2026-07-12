class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> tmep = arr;
        sort(tmep.begin(),tmep.end());
        unordered_map<int,int> mp;
       int rank = 1;
        for(auto c : tmep){
            if(mp.find(c)==mp.end()){
                mp[c]  =  rank++;
            }
            
        }
        vector<int> ans;
        for(auto x : arr){
            ans.push_back(mp[x]);
        }
        return ans;
    }
};