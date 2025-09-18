
class Solution {
public:
    void trim(TreeNode* root,int lo,int hi){
        if(root==NULL) return;
        while(root->left!=NULL){
            if(root->left->val < lo) root->left = root->left->right; //to get big value
            else if(root->left->val > hi) root->left = root->left->left;    //to get small value left->left
            else break;
        }
        while(root->right!=NULL){
            if(root->right->val > hi) root->right = root->right->left;  //less
            else if(root->right->val < lo) root->right= root->right->right; //more
            else break;
        }
        trim(root->left,lo,hi); //for every node onleft 
        trim(root->right,lo,hi);    //for eveyr node in right
        
    }
    TreeNode* trimBST(TreeNode* root, int lo, int hi) {
        TreeNode* dummy  = new TreeNode(INT_MAX); 
        dummy->left = root;
        trim(dummy,lo,hi);
        return dummy->left; //original tree
    }
};