class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n  = t.size();
        if(m < n) return "";
        unordered_map<char , int> mp;
        for(char &c : t){
            mp[c]++;
        }
        int reqCount = n;
        int i = 0 , j = 0;
        int windSize = INT_MAX;
        int start_i = 0;
        while(j < m){
            int ch = s[j];
            if(mp[ch] > 0) reqCount--; //if found in map 
            mp[ch]--;
            while(reqCount==0){
                int currentWind = j - i +1;
                if(windSize > currentWind){
                    windSize = currentWind;
                    start_i = i;       
                } 
                //now shrinking 
                mp[s[i]]++;
                if(mp[s[i]] > 0) reqCount++; //if leaving letter required then +
                i++;
            }
            j++;
        }
        if(windSize == INT_MAX) return "";
        else return s.substr(start_i , windSize);
    }
};