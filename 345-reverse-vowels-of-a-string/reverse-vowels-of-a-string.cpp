
class Solution {
public:
    bool isVowel(char c){
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return true;
    }
    return false;
    }
    string reverseVowels(string s) {
      vector<char> vowels; //useful to apply reverse on the vowels 
     for(char c:s){         //c collects each char of string s
        if(isVowel(c)) vowels.push_back(c);
     }
     reverse(vowels.begin(),vowels.end());
     string t = "";
     int idx = 0;
     for(char c:s){ 
        if(isVowel(c)) t += vowels[idx++];  //push the sorted vowels in the string t
        else t += c;
     }
     return t;
    }
};