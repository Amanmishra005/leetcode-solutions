class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        string ans = "";
        for(auto x : s){
            if(ans.size() != 0 && abs(ans.back() - x) == 32){   ///a = 97 , A = 65 abs(a-A) = 32 same char
                ans.pop_back();
            }
            else ans += x;
        }
        return ans;
    }
};