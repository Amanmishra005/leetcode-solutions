class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> alt = {0};
        int g=0;
        for(int i=0;i<gain.size();i++){
            g +=gain[i];
            alt.push_back(g);
        }
        int n = alt.size();
        sort(alt.begin(),alt.end());
        return alt[n-1];
    }
};