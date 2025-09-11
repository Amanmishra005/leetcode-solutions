class Solution {
public:
    bool isVowel(char c){
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return true;
    }
    return false;
    }
    string sortVowels(string s) {
      vector<char> vowels;
      for(char c: s){
        if(isVowel(c)) vowels.push_back(c);
      }
      sort(vowels.begin(),vowels.end());
      string t= "";
      int idx = 0;
      for(char c:s){
        if(isVowel(c)) t += vowels[idx++];
        else t +=c;
      }
      return t;
    }
};