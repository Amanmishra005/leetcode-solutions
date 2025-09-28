class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n,0);
        if(k==0) return ans;

        int i,j;
        if(k>0){
             i = 1;
             j = k;         //length of window 
        }
        else{   //k<0
             i = n- abs(k);
            j = n-1;
        }
        int winSum = 0;
        //sum of the current window
        for(int idx = i;idx<=j;idx++){ 
            winSum += code[idx];
        }
        
        for(int k=0;k<n;k++){
            ans[k]  =winSum;      // store current sum   
            winSum -= code[i % n];      //window leaving elemen
            i++;
            winSum += code[(j+1) % n];  //new ele
            j++;
        }
        return ans;

    }
};