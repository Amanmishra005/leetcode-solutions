class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        set<int> st;
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(nums1[i]== nums2[j]){
                st.insert(nums2[j]);
            }
            }
            
        }
        vector<int> vec;
        for(auto x : st){
            vec.push_back(x);
        }
        return vec;
    }
};