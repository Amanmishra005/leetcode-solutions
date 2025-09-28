class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int> ,greater<int>> min; //if largest ask then take min heap and vice versa 
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            min.push(nums[i]);
            if(min.size()>k){
                min.pop();
            }
        }
        return min.top();
    }
};