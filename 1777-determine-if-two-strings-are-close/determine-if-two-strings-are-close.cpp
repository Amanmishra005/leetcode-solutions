class Solution {
public:
    bool closeStrings(string word1, string word2) {
       int m = word1.size();
       int n = word2.size();
       if(m != n) return false;
       vector<int> freq1(26);          //a, b, c , .... z for filling occurene
       vector<int> freq2(26);
       for(int i=0;i<m;i++){        //since m && n should be equal so both work in one loop we can 
        char ch1 = word1[i];
        char ch2 = word2[i];
        int idx1 = ch1 - 'a';      //c - a = 2 so at 2 index fill 1 i.e c occured one time till now
        int idx2 = ch2 - 'a';
        freq1[idx1]++;              //occurence increase
        freq2[idx2]++;
       }
       for(int i=0;i<26;i++){
        if(freq1[i] != 0 && freq2[i] != 0) continue;       //without this exchnage not possible i.e existence 
        if(freq1[i] == 0 && freq2[i] == 0) continue;       //exchange with only the available present char 
        return false;
       }
       sort(freq1.begin() , freq1.end());
       sort(freq2.begin() , freq2.end());
        return freq1==freq2;  //if freq same then exchange with those char possible 
    }
};