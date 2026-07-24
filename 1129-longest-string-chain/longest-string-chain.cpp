class Solution {
public:
bool ispred(string& word1 , string word2){
    int M = word1.size();
    int N = word2.size();
    if(M >= N || N-M!=1) return false;
    int i = 0 , j = 0;
    while(i<M && j<N){
        if(word1[i]==word2[j]) i++;
        j++;
    }
    return i==M;
}
static bool onlength(string& word1 , string& word2){
    return word1.length() < word2.length();
}
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end() , onlength);
        vector<int> dp(n , 1);
        int longchain = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(ispred(words[j] , words[i])){
                     dp[i] = max(dp[i] , dp[j] +1);
                }
                longchain = max(longchain , dp[i]);
            }
        }
        return longchain;
    }
};