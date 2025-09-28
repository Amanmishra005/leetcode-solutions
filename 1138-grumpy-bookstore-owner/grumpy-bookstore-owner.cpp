class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int k = minutes;
        int prevLoss = 0;

        // Initial loss window
        for (int i = 0; i < k; i++) {
            if (grumpy[i] == 1) prevLoss += customers[i];
        }

        int maxLoss = prevLoss;
        int maxIdx = 0;
        int i = 1, j = k;

        while (j < n) {
            //

            if (grumpy[j] == 1) prevLoss += customers[j];
            if (grumpy[i - 1] == 1) prevLoss -= customers[i - 1];

            if (prevLoss > maxLoss) {
                maxLoss = prevLoss;
                maxIdx = i;
            }            
            i++;
            j++;
        }
        // remove grumpiness in best window
        for (int i = maxIdx; i < maxIdx + k && i < n; i++) {
            grumpy[i] = 0;  //become non-grumpy -> max customers
        }

        // Calculate total satisfied customers
        int total = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) total += customers[i];
        }

        return total;  
    }
};
