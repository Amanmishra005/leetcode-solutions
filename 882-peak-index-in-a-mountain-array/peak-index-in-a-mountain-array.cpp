class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;

        while (low < high) {
            int mid = (low + high) / 2;

            if (arr[mid] < arr[mid + 1]) {
                // we are on the increasing slope
                low = mid + 1;
            } else {
                // we are on the decreasing slope (or peak)
                high = mid;
            }
        }

        return low; // low == high → peak index
    }
};
