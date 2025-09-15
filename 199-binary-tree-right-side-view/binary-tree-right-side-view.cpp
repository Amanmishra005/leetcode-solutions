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
int levels(TreeNode* root){
    if(root==NULL) return 0;
    return 1+max(levels(root->left),levels(root->right));
};
void nthLevel(TreeNode* root,int currL,int level,vector<int>& ans){
    if(root==NULL) return;
    if(currL==level){
       ans[currL] = root->val;  //last node at that level will get stored since we are we r visting each node at that level so the last node that llevel will get stored
        return; 
    }
    nthLevel(root->left,currL+1,level,ans);
    nthLevel(root->right,currL+1,level,ans);
}
void LevelOrder(TreeNode* root,vector<int>& ans){    //prints all nodes at the given level in a binary tree 
    int n = ans.size();
    for(int i=0;i<n;i++){
        nthLevel(root,0,i,ans);
       
    }
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(levels(root),0);   //     size,intial value->0
       LevelOrder(root,ans);
       return ans;

       

    }
};