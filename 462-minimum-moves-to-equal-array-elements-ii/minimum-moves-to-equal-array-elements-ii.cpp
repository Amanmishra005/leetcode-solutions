class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int moves = 0;
        int medi = 0;
         if(nums.size()%2!=0) medi = nums[nums.size()/2];
            else medi = (nums[nums.size()/2 - 1] + nums[nums.size()/2]) / 2;
        for(int i=0;i<nums.size();i++){
           moves += abs(medi - nums[i]);

        }
        return moves;
    }
};