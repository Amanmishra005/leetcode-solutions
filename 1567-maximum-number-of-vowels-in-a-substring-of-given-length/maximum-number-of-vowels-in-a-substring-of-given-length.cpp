class Solution {
public:
     bool isvowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int n  = s.size();
        int i = 0 , j = 0;
       int count = 0;
       int maxwin = 0;
       while(j < n){
        if(isvowel(s[j])) count++;
        if(j - i +1 == k){
            maxwin = max(maxwin , count);
            if(isvowel(s[i])){
                count--;    //leaving window conatainig vowel
            }
            i++; //slidng the window
        }
        j++;
       }
        return maxwin;
    }
};