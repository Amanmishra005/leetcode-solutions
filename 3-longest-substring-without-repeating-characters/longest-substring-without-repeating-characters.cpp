class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0 , j= 0;
        int result = 0;
        unordered_set<char>  st;
        while(j < s.length()){
            while(st.find(s[j]) != st.end()){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            result = max(result , j - i +1);
            j++;
        }
        return result;
    }
};