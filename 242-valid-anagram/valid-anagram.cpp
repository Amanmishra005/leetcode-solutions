class Solution {
public:

    bool isAnagram(string s, string t) {
       if(s.length()!=t.length()) return false;
       unordered_map<char,int> map1;
       for(int i=0;i<s.length();i++){
             map1[s[i]]++;
       }
       for(int i=0;i<t.length();i++){
        char ch = t[i];
        if(map1.find(ch)==map1.end()) return false;//if ch of string t not found in map s 
              map1[ch]--;     //if found then remove           
            if(map1[ch]==0) map1.erase(ch);
        }
        return true;
       }
       
       
};
