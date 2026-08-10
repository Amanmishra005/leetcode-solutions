class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int currentWind = 0;
        for(int i=0;i<minutes;i++){
            if(grumpy[i]==1){
                currentWind += customers[i];
            }
        }
        int maxUnsatisfied = currentWind;
        int i =0;
        int j = minutes; //each limit window;
        while(j < n){
            if(grumpy[j]==1){
                currentWind += customers[j]; //new element of new window --> inclusion
            }
            if(grumpy[i]==1){
                currentWind -= customers[i];    //leaving window
            }
               
                maxUnsatisfied = max(maxUnsatisfied , currentWind);
                i++;
                j++;
            }
        
        int total  = maxUnsatisfied; //satisfying by calm
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                total += customers[i];
            }
        }
        return total;
    }
};