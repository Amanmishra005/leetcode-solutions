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
    int preorderIndex = 0;
    TreeNode* build(vector<int>& preorder,vector<int>& inorder,int left,int right){
        if(left>right) return NULL;
        //root from preorder
        int rootval = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootval);
        //root from inorder apply linear search
        int mid = -1;
        for(int i=left;i<=right;i++){
            if(inorder[i] == rootval){
                mid = i;
                break;
            }
        }
        //use recursion to build left right subtree
        root->left = build(preorder,inorder,left,mid-1);
        root->right = build(preorder,inorder,mid+1,right);
        return root;

    }
     TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder){
        int n = inorder.size()-1;
        return build(preorder,inorder,0,n);
     }
   
};