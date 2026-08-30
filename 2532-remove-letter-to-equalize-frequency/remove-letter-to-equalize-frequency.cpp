class Solution {
public:
    bool equalFrequency(string word) {
        vector<char> vec(26);
        for(auto ch : word) vec[ch - 'a']++; //stored frequency of eah char 
        for(int i=0;i<26;i++){
            if(vec[i]){
                vec[i]--;       //remove any char and check --> hit and trial
                int freqcheck = *max_element(vec.begin(),vec.end()); 
                bool check = true;
                for(int j=0;j<26;j++){
                    if(vec[j] && vec[j] != freqcheck) check = false; //if that char not equal freq
                }
                vec[i]++;   //restore that one try removing next one char 
                if(check) return true;
                
            }
        }
        return false;
    }
};