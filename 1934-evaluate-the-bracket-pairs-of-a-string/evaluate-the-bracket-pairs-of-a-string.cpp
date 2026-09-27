class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for(auto x : knowledge){
            mp[x[0]] = x[1];
        }
        string result = "";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
            string ans = "";
                int j = i+1;
                while(s[j]!=')'){
                    ans += s[j];
                    j++;
                }
                if(mp.find(ans)!=mp.end()){
                    result += mp[ans];
                }else{
                    result += '?';
                }
                i = j;
            }else{
                result += s[i];
            }
        }
        return result;
    }
};