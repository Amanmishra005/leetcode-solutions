class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for(auto ch : word){
            if(islower(ch))  count++;
        }
       if(count==word.size() || count ==0) return true; //no char or whole string 
       if(count==word.size()-1 && isupper(word[0])) return true; //only first char is upper
       return false;
    }
};