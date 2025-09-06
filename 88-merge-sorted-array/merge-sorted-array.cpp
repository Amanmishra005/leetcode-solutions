class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;       // last valid element in nums1
        int j = n - 1;       // last element in nums2
        int k = m + n - 1;   // last position in nums1

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) { //comparing from last which array element is bigger
                nums1[k--] = nums1[i--]; //catch the bigger value and decrease the index to the left
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // Copy remaining nums2 elements (if any)
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
