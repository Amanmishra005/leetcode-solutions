class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
     vector<vector<string>> ans;
     unordered_map<string,vector<string>> mp;
     for( auto str: arr){
        string lex = str;
        sort(lex.begin(),lex.end());
        if(mp.find(lex)==mp.end()){     //if not found then create vector and store
            vector<string> v;
            v.push_back(str);
            mp[lex] = v;    // assigns/replaces the whole vector.
        }
        else{
            mp[lex].push_back(str); //if found then push that string 
        }
     }
     for(auto x:mp){
        vector<string> v = x.second;    //catch the original stringg 
        ans.push_back(v);       //push all the vector into a single vector ans
     }
     return ans;
    }
};