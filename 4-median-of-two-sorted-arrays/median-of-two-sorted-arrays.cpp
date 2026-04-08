class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        for(int i=0;i<nums1.size();i++){
            v.push_back(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            v.push_back(nums2[i]);
        }
        int s = v.size();
        sort(v.begin(), v.end());
        if(s%2==1){
            return v[s/2];
        }else{
            return (v[s/2] + v[s/2 - 1]) /2.0;
        }
    }
};