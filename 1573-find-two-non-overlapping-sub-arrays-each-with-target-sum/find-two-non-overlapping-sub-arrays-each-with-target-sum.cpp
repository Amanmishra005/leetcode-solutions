class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int i =0 , j = 0;
        int sum = 0;
        int minlenIndex = INT_MAX;
        vector<int> bestSum(n , INT_MAX);
        int result = INT_MAX;
        while(j<n){
            sum += arr[j];
            while(i<j && sum > target){
                sum -= arr[i++];
            }
            if(sum == target){
                int len = j-i+1;
                if(i>0 && bestSum[i-1] != INT_MAX){
                    result = min(result , len + bestSum[i-1]);
                }
                minlenIndex = min(len , minlenIndex);
            }
            bestSum[j] = minlenIndex;
            j++; 
        }
        if(result == INT_MAX) return -1;
        else return result;
    }
};