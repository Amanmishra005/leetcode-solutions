class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int m = nums.size();
        vector<int> vec = nums;
        sort(vec.begin() , vec.end());
        int grpNum = 0;
        unordered_map<int,int> numToGrp;
        numToGrp[vec[0]] = grpNum;      //first ele into grp 0

        unordered_map<int, list<int>> grpToList;  //list acts like doubley ll soo insertion or deletion in o(1)
        grpToList[grpNum].push_back(vec[0]);     //acc grp contain which ele

        for(int i=1;i<m;i++){
            if(abs(vec[i] - vec[i-1]) > limit){
                grpNum += 1;        //if greater than limit than push that ele into another grp
            }
            numToGrp[vec[i]] = grpNum; 
            grpToList[grpNum].push_back(vec[i]);
        }
        vector<int> result(m);
        for(int i=0;i<m;i++){
            int num = nums[i];
            int grp = numToGrp[num];
            result[i] = *(grpToList[grp].begin()); //* used to defrence as list gives iterator only
            grpToList[grp].pop_front();
        } 
        return result;
    }
};