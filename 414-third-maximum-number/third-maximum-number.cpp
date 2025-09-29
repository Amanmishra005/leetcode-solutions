class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> seen;
        priority_queue<int, vector<int>,greater<int>> min;
        for(auto num : nums){
            if(seen.count(num)) continue;   //if duplicate found then skip 
            seen.insert(num);              //else insert 
           min.push(num);
            if(min.size()>3){
                min.pop();
            }
        }
        if(min.size()<3){
            while(min.size()>1){
                min.pop();
            }
        
        }
        return min.top();
    }
};