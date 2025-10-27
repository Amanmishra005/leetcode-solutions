class Solution {
public:
   
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int ele: nums){
            if(ele%2 == 0) mp[ele]++; // even ele with their freq stored 
        }
        if(mp.empty()) return -1;
        int maxfreq = -1,ans = -1; 
        for(auto x: mp){
            int ele = x.first,freq = x.second;
            if(freq > maxfreq || (freq== maxfreq && ele < ans)){    //if freq same then take the smaller ele
                maxfreq = freq;
                ans = ele;
            }
        }
        return ans;
    }
};
