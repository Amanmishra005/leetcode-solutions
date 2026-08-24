class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string r1 = "";
        string r2 = "";
        for(auto ch : word1){
            r1 += ch;
        }
        for(auto ch : word2){
            r2 += ch;
        }
        return r1==r2;
    }
};