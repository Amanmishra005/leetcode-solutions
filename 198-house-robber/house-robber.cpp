class Solution {
public:
    int rob(vector<int>& nums) {
        int  n = nums.size();
        if(n==1) return nums[0];
        //const space 
        int prevprev = 0;
        int prev = nums[0];         //only one house then 
        for(int i=2;i<=n;i++){
        int steal = nums[i-1] + prevprev;//current house looting i-1  + amount looted til now not the adjacent one but i.e i-2
            int skip = prev; //if not looted current one take profit till the adjacent house 
            int temp = max(steal , skip);
            prevprev = prev;
            prev =  temp;
        }
        return prev;
    }
};
