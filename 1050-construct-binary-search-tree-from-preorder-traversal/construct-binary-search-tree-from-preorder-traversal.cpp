//preOrder  = root left right ,so catch the Ist element i.e. root and then traverse the vector and insert left and right according to their values from insert fn .
class Solution {
public:
    TreeNode* insert(TreeNode* root,int val){
        if(root==NULL) return new TreeNode(val);
        if(root->val > val){            //less than val on left side
            root->left = insert(root->left,val);
        }
        else{   //root->val < val      ->go right if want more 
            root->right = insert(root->right,val);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* root = new TreeNode(pre[0]);  //Ist element i.e. root of the tree
        for(int i =1;i<pre.size();i++){
            insert(root,pre[i]);        //traverse and insert 
        }
        return root;
    }
};