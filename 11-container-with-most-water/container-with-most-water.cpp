class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0 , j = n-1;
        int most = 0;
        while(i < j){
            int area = min(height[i] , height[j]) * (j-i);
            most = max(most , area);
            if(height[i] < height[j]) i++;
            else j--;
        }
        return most;
    }
};