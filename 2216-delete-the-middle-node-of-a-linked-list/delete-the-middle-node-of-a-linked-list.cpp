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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* curr = head;
        ListNode* sl = curr;
        ListNode* fs =  curr;
        while(fs!=NULL && fs->next!=NULL){
            curr = sl;
            sl = sl->next;
            fs = fs->next->next;
        }
       curr->next = sl->next;
        return head;
    }
};