class Solution {
public:
typedef pair<int,int> pi;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pi> max; //max size k
        for(int ele: arr){
            int distance  = abs(x-ele);
            max.push({distance,ele});     //compare on the basis of distance
            if(max.size()>k) max.pop();
        }
        vector<int> ans;
        while(!max.empty()){
            ans.push_back(max.top().second);
            max.pop();
        }
        sort(ans.begin(),ans.end());    //to avoid num with same dis. from each side 
        return ans;
    }
};
