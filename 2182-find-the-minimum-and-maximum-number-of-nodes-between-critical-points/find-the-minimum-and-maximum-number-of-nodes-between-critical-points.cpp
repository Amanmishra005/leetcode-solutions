/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp = head;
        ListNode* tempn = head->next;
        ListNode* tempnn = head->next->next;
        int idx = 1;        //curr idx point
        int firstidx = -1;      //to find max dis 
        int secidx = -1;

        if(tempnn==NULL) return {-1,-1};
        int prevCp = -1; //to find min dis 
        int currCp = -1;
        int minimumdis = INT_MAX;

        while(tempnn){
            if(tempn->val > temp->val && tempn->val > tempnn->val || tempn->val < temp->val && tempn->val < tempnn->val){
                if(firstidx == -1) firstidx = idx;
                else secidx = idx;

                prevCp = currCp;
                currCp  = idx;

                if(prevCp != -1){
                    int cpdis  = currCp - prevCp;
                    minimumdis = min(minimumdis , cpdis);
                }

            }
            temp = temp->next;
            tempn = tempn->next;
            tempnn = tempnn ->next;
            idx++;
        }
        if(secidx == -1) return {-1,-1}; //if only one critical tab return kardo -1 -1
        int maxdis = secidx - firstidx;
        return {minimumdis , maxdis};

    
    }
};