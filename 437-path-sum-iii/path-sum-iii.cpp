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
void helper(TreeNode* root ,long long sum,int& count){
    if(root==NULL) return;
    if((long long)root->val==sum){          //if current node equal to sum then we found a path
        count++;
    }
    helper(root->left ,sum-(long long)(root->val),count);
    helper(root->right ,sum-(long long)(root->val),count);
    
}
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        int count = 0;
        helper(root,targetSum,count);
        count += pathSum(root->left, targetSum) + pathSum(root->right, targetSum);  //checking for all possible paths
        return count;
    }
};