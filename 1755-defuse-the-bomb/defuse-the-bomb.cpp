class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n,0);
        if(k==0) return ans;

       int windowSize = abs(k);
       int sum = 0;
       
        if(k>0){
            for(int i=1;i<=k;i++){
                sum += code[i % n];     //circular array to avoid out of bound
            }
        }
        else { //k<0
            for(int i=n+k ;i<n;i++){
                sum += code[i % n];
               
            }
        }
        for(int i=0;i<n;i++){
            ans[i] = sum;
            if(k>0){
                sum -= code[(i+1) % n];
                sum += code[(i+k+1)%n];
            }
            else{
                sum -= code[(i+n+k)%n];
                sum += code[i%n];
            }
         }
       
       return ans;

    }
};