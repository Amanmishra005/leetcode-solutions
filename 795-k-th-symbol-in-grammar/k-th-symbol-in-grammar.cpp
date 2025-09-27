class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0;  //starts with 0
        if(k%2==0){     //checking for even case
            int prevAns =  kthGrammar(n-1,k/2); //root index
            if(prevAns==0) return 1;        //flip 
            else return 0;
        }
        else{       //k%2!=0
            int prevAns =  kthGrammar(n-1,k/2+1);       //root odd index
            return prevAns;
        }
        return k;
    }
};