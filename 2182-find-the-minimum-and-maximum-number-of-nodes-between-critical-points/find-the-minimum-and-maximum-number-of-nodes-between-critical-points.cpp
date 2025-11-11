
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx =1;
        int fidx = -1;                      //firstindex ->left
        int sidx = -1;                      //lastindex ->right
        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* c = head->next->next;
        if(c==NULL) return {-1,-1};
        //for min
        int f =-1;
        int s =-1;
        int mind = INT_MAX;
        while(c){
            if(b->val > a->val && b->val > c->val || b->val < a->val && b->val < c->val){               //maxd
                if(fidx==-1) fidx = idx;
                else sidx = idx;
                //mindistance
                f= s;
                    s = idx;
                    if(f!=-1){
                        int d = s - f;
                    mind = min(mind,d);
                    }
            }
            a=a->next;
            b = b->next;
            c = c->next;
            idx++;
        }
        if(sidx==-1) return {-1,-1}; // one critical point then return vector -1,-1
        int maxd = sidx-fidx;
        return{mind,maxd};
    }
};