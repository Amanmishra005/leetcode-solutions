class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        
        int mineleidx = 0;
        
        int maxeleidx= 0;
        
        for(int i=0;i<n;i++){
            if(nums[mineleidx] > nums[i]){
                
                mineleidx = i;
            }
            if(nums[maxeleidx] < nums[i]){
               
                maxeleidx = i;
            }
        }
      
        //removal of elements 2 , 10, 7 ,5, 4, 1,8,6
        int left = max(mineleidx , maxeleidx) + 1;    //1-> idx 5+1 = 6 ,ele left after deletion -> 8,6->idx 6

        int right = n - min(mineleidx , maxeleidx); //8-1 = 7-> after del lefft -> 2 idx from right 7
        int both = min(mineleidx , maxeleidx) + 1 + n - max(mineleidx , maxeleidx); //idx 2 + (8-5); idx ->5
        return min({left , right , both});
    }
};