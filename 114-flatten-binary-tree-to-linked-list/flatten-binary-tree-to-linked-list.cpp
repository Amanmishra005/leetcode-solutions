/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->left!=NULL){
                //save right
                TreeNode* r = curr->right;
                curr->right = curr->left; 
               
                //finding predecessor
                TreeNode* pred = curr->left;
                while(pred->right!=NULL) pred = pred->right;
                //linking 
                pred->right = r;
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
        //connecting nodes 
        TreeNode* temp = root;
        while(temp->right!=NULL){
            temp->left = NULL;
            temp = temp->right;
        }

    }
};