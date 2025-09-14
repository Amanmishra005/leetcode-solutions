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
//void postOrder(TreeNode* root,vector<int>& ans){
//     if(root==NULL) return;
//     postOrder(root->left,ans);
//     postOrder(root->right,ans);
//     ans.push_back(root->val);
    
// }
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         postOrder(root,ans);
//         return ans;
//     }

//Iterative method ->just push left then right and reverse the vector
 vector<int> postorderTraversal(TreeNode* root){
    vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            //right first for reversal order in the stack
             if(temp->left!=NULL) st.push(temp->left);
            if(temp->right!=NULL) st.push(temp->right);
           
        }        
         reverse(ans.begin(),ans.end());
         return ans;
    }



};