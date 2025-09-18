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
    TreeNode* iop(TreeNode* root){
        TreeNode* pred = root->left;
        while(pred->right!=NULL){
            pred = pred->right;
        }
        return pred;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val == key){   //node to be deleted found
            //case 1: no child
            if(root->left==NULL && root->right==NULL) return NULL;
            //case2: 1 child node
            if(root->left==NULL || root->right==NULL){
                if(root->left!=NULL) return root->left;
                else return root->right;
            }
              ////case3: 2 child Nodes
            if(root->left!=NULL && root->right!=NULL){
                 //REPLACE the root with its eiher predecessor or successor
            //after replacing delete the predecessor 
                TreeNode* pred  = iop(root);     //either use iop or ios to catch the node
                root->val = pred->val;  //keep the value before deletin pred from its origianl location
                root->left = deleteNode(root->left,pred->val);  //pred -> root left 
            }
        }
        else if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else{
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};