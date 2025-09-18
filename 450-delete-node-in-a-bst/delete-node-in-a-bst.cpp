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
    TreeNode* ios(TreeNode* root){
        TreeNode* sucess = root->right;
        while(sucess->left!=NULL){
            sucess = sucess->left;
        }
        return sucess;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        if(root->val==key){
            if(root->left==NULL && root->right==NULL) return NULL;
            if(root->left==NULL || root->right==NULL){
                if(root->left!=NULL) return root->left;
                else return root->right;
            }
            if(root->left!=NULL && root->right!=NULL){
                TreeNode* sucess = ios(root);
                root->val = sucess->val;
                root->right = deleteNode(root->right,sucess->val);
            }
            
        }
        if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else{
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};