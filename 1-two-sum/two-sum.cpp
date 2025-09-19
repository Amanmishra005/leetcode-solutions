class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int n = nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            int rem = target - nums[i];
            if(m.find(rem)!=m.end()){       //if rem ele found in map
                result.push_back(m[rem]);
                result.push_back(i);    //index's value + rem = tareget
            }
            else m[nums[i]] = i;
        }
        return result;
    }
};
