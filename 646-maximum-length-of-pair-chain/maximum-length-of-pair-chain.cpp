class Solution {
public:
int n;
int dp[1001][1001];
int mlpc(vector<vector<int>>& pairs , int prevele , int curridx){
    if(curridx>=n)return 0;
    if(prevele != -1 && dp[prevele][curridx]!=-1) return dp[prevele][curridx];
    int take = 0;
    if(prevele == -1 || pairs[prevele][1] < pairs[curridx][0]){
        take = 1 + mlpc(pairs , curridx , curridx+1);
    }
    int skip = mlpc(pairs , prevele , curridx+1);
    if(prevele != -1) dp[prevele][curridx] = max(take ,skip);
    return  max(take , skip);
}
    int findLongestChain(vector<vector<int>>& pairs) {
          n = pairs.size();
          memset(dp , -1 , sizeof(dp));
        sort(pairs.begin() , pairs.end());
        return mlpc(pairs , -1 , 0);
    }
};