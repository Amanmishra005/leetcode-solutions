class Solution {
public:
bool palindrome(string s){
    string s1 = s;
    reverse(s1.begin(),s1.end());
    return s1 == s;
}
    void parts(string s ,vector<vector<string>>& res  , vector<string>& palin){
        if(s.size()==0){
            res.push_back(palin);
            return;
        }
    for(int i=0;i<s.size();i++){
        string part = s.substr(0, i+1);
        if(palindrome(part)){
            palin.push_back(part);
            parts(s.substr(i+1) , res , palin);
            palin.pop_back();
        }

    }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> palin;
        parts(s, res , palin);
        return res;
    }
};