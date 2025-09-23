class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mp;  //fill the remain of the ele in the arr
        for(auto ele : arr){
            ele = ((ele % k) + k)%k;      //to handle negative nums 
            mp[ele]++;
        }
        if(mp.find(0)!=mp.end()){       //to handle zeroes in map
            if(mp[0]%2!=0) return false;    //[0] is the key i.e ele 
            mp.erase(0);
        }
        
        for(auto x: mp){
            int ele = x.first;
            int rem = k - ele;      //to find the pair 
            if(mp.find(rem)==mp.end()) return false;    //rem exists check
            if(mp[ele]!=mp[rem]) return false;  //frequeny check 
        }
        return true;
    }
};