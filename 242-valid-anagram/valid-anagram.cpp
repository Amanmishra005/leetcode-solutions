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
        if(map1.find(ch)!=map1.end()){  //find ch of string t in string of string s
              map1[ch]--;               //found then remove char of string s in map1
            if(map1[ch]==0) map1.erase(ch); //char[s]  = char  [t] then delete 
        }
            else return false;
        }
        if(map1.size()>0) return false;     //distinct  map2 so no anagram
        return true;
       }
       
       
};