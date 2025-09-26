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
ListNode* left;
    bool checkPal(ListNode* right){
        if(right==NULL) return true;
            bool isPal = checkPal(right->next);     //now right is at the tail posi through deep recursion

        if(isPal==false) return false;          
        if(left->val!=right->val) return false;

        left = left->next;
        return true;
    }
    bool isPalindrome(ListNode* head) {
      left = head;
      return checkPal(head);
    }
};