class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        unordered_map<int,int> m;
        for(auto ele: arr){
            m[ele]++;           //catching value of arr in ele of map m
        }
        for(int i=100;i<=999;i+=2){
            int x = i;         //store the number to be checked in x so that original num can later be pushed
            int a = x%10;   //ones place digit
            x /=10;
            int b = x%10;    //tens place digit
            x /=10;
            int c = x;  //
            if(m.find(a)!=m.end()){
                m[a]--;
                if(m[a]==0) m.erase(a);
                if(m.find(b)!=m.end()){
                    m[b]--;
                    if(m[b]==0) m.erase(b);
                    if(m.find(c)!=m.end()) ans.push_back(i);  //all ele found then push
                    m[b]++; //if number found then restore the digit b again 
                }
                m[a]++; //restore again if number found 
            }
        }
        return ans;
    }
};