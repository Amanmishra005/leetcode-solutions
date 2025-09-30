class Solution {
public:
typedef pair<int,int> pi;       //alias
    vector<int> topKFrequent(vector<int>& nums, int k) {  
        unordered_map<int,int> mp;   //ele,fre
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pi,vector<pi>, greater<pi>> min;
        //now traverse in map
        for(auto x: mp){
           min.push({x.second,x.first}); //<freq,ele> (to compare the freq not ele and keep lower frequency ele at the top to pop )  
           if(min.size()>k) min.pop();
        }

        vector<int> ans;   
        while(!min.empty()){
            int ele = min.top().second; //extract top k frequent ele from queue 
            ans.push_back(ele);
            min.pop();
        }   
        return ans;
        
    }
};