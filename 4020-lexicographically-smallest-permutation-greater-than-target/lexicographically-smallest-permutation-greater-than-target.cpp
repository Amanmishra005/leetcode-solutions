class Solution {
public:
string result = "";
bool solve(string& curr, vector<int>& count , string& target , int i , bool greater){
    if(i==target.size()){   //base case
        if(greater){
            result = curr;
            return true;
        }
        return false;
    }
    for(char ch = 'a';ch<= 'z';ch++){
        if(count[ch - 'a'] == 0) continue; //char not exist in target
        if(greater == false && ch < target[i]) continue;    
        curr.push_back(ch);     //DO
        count[ch-'a']--;

        bool isGreater = greater || ch > target[i]; //did we took the greater char till now 
        if(solve(curr , count , target , i+1, isGreater)) return true;      //explore

        //undo 
        curr.pop_back();
        count[ch - 'a']++;
    }
    return false;
}

    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> count(26);
        for(auto ch : s){
            count[ch - 'a']++;
        }
        string curr;
        solve(curr, count , target , 0 , false);
        return result;
    }
};