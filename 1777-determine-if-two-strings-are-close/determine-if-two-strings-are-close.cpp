class Solution {
public:
    bool closeStrings(string str1, string str2) {
        if(str1.length()!=str2.length()) return false;
        unordered_map<char,int> mp1,mp2;
        for(int i=0;i<str1.length();i++){
            mp1[str1[i]]++;              //catching char of strings 
            mp2[str2[i]]++;
        }
        //compare chars
        for(auto x : mp1){
            char ch = x.first;       //i.e char 
            if(mp2.find(ch)==mp2.end()) return false;
        }
        //now frequency of each char 
        unordered_map<int,int> h1,h2; 
        for(auto x : mp1){
            int frq = x.second;
            h1[frq]++;         //filling up the freq     
        }
        for(auto x: mp2){
            int frq = x.second;
            h2[frq]++;
        }
        //compare on frq
        for(auto x: h1){
            int key = x.first;
            if(h2.find(key)==h2.end()) return false;    //found 
            if(h1[key]!=h2[key]) return false;      //compare freq
        }
        return true;
    }
};  