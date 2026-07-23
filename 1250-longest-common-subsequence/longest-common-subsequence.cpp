class Solution {
public:
    int dp[1001][1001];
    int solve(string& text1 , string& text2,int i , int j){
        int m = text1.size();
        int n = text2.size();
       
        if(i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i] == text2[j]){       //if char matches sequentially 
            return  dp[i][j] = 1 + solve(text1 , text2 , i+1 , j+1);
        }
        return dp[i][j] = max(solve(text1 , text2 , i+1,j) ,     //  we can either skip from text1 or from text2
                    solve(text1 , text2 , i , j+1));            //text1 skip i+1 , text2 skip j+1 
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp , -1, sizeof(dp));
        return solve(text1 , text2 , 0 , 0);
    }
};