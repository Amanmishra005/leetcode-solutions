class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int s1 = arr1.size();
        int s2 = arr2.size();
        int dv = 0;
      
        for(int i=0;i<s1;i++){
              bool valid  = true;
            for(int j=0;j<s2;j++){
                if(abs(arr1[i]-arr2[j]) <= d) valid = false;
            
            }
            if(valid) dv++;
        }
        return dv;
    }
};