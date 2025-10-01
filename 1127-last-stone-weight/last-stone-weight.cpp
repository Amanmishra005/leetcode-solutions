class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max;
        for(int i=0;i<stones.size();i++){
            max.push(stones[i]);
        }
        int x,y;
        while(max.size()>1){
            int x = max.top();
            max.pop();
            int y= max.top();
            max.pop();
            int dif = abs(x-y);
            max.push(dif);
        }
        return max.top();
    }
};