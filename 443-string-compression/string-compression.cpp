class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0;
        int i = 0;
        while(i<n){
            char current = chars[i]; 
            int count = 0;
            while(i<n && current==chars[i]){  //same char then count increase 
                count++;
                i++;
            }
            chars[index] = current; //store curr char at that index 
            index++;
            if(count>1){
                string count_str = to_string(count);    //if 12 -> "1","2" then store it also
                for(char& ch : count_str){
                    chars[index] = ch;                      //at index 
                    index++;                                //move for the next current char 
                }
            }
        }
        return index;                                   //it will reach the end that is thee compressed size 
    }
};