class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        unordered_set<int> s;
        for(auto x : m){        //x varibales storing from map => m
            int fre = x.second;//second =frequency of any number in map
            if(s.find(fre)!=s.end()) return false; //same freq check 
            else s.insert(fre); //i.e feq is unique till now so keep inserting others
        }
        return true;
    }
};