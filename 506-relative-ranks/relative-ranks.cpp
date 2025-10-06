class Solution {
public:
     typedef pair<int,int> pq;
     
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue<pq> max;
        for(int i=0;i<score.size();i++){
            max.push({score[i],i});
            
        }
        vector <string> result(n);
        int rank = 1;
        while(!max.empty()){
            int val = max.top().first;
            int index = max.top().second;
            max.pop();
            if(rank ==1) result[index] = "Gold Medal";
            else if(rank == 2) result[index] = "Silver Medal";
            else if (rank==3) result[index] = "Bronze Medal";
            else result[index] = to_string(rank);

            rank++;
        }
        return result;
    
        
        

    }
};