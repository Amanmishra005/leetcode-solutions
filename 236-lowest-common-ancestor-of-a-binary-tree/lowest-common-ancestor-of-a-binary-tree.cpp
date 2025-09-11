/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==NULL || root==p || root==q) return root;
       TreeNode* left = lowestCommonAncestor(root->left,p,q);//checking left if p,q present
       TreeNode* right  = lowestCommonAncestor(root->right,p,q); //checking right

       if(left!=NULL && right!=NULL) return root;   //one of each p & q present in either left or right

       if(left!=NULL ) return left;//both in left
       else return right;  //both in right

    }
};