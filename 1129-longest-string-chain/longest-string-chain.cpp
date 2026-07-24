class Solution {
public:
    int  n;
    int dp[1001][1001];
    bool ispred(string& prev , string& curr){
        int M = prev.length();
        int N = curr.length();
        if(M >= N || N-M!=1) return false;
        int i = 0, j = 0;
        while(i<M && j <N){
            if(prev[i] == curr[j]) i++;
            j++;
        }
        return i==M;
    }
    int lis(vector<string>& words , int prevele , int currele){
        if(currele>=n) return 0;
        int take  = 0;
        if(prevele!= -1 && dp[prevele][currele]!=-1) return dp[prevele][currele];
        if(prevele==-1 || ispred(words[prevele],words[currele])){
            take = 1 + lis(words , currele , currele + 1);
        }
        int skip = lis(words , prevele , currele +1 );
        if(prevele != -1){
            dp[prevele][currele] = max(take , skip);
        }
        
        return max(take , skip);
    }
    static bool onlength(string& word1 , string& word2){        //static since comparator requirement on sort 
        return word1.length() < word2.length();
    }
    int longestStrChain(vector<string>& words) {
        n = words.size();
        memset(dp , -1 , sizeof(dp));
        sort(words.begin(),words.end() , onlength);
        return lis(words , -1 , 0);
    }
};