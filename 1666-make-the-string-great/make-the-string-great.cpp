class Solution {
public:
    string makeGood(string s) {
        int n  = s.size();
        string ans = "";
        for(auto c : s){
            if(ans.size() !=0 && abs(ans.back() - c)==32){
                ans.pop_back();
            }
            else ans += c;
        }
        return ans;
    }
};