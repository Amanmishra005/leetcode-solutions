class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        double ans =0;
       int notinc = n * 0.05;
       for(int i= notinc;i< n- notinc;i++){
        ans += arr[i];
       }
       return ans / (n-2 * notinc);
    }
};