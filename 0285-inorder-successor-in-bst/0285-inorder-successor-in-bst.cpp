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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* succ=nullptr;
        
        if(root==nullptr){
            return root;
        }
        while(root!=nullptr){
            if(p->val>=root->val){
                root=root->right;
            }
            else{
                succ=root;
                root=root->left;
            }
        }//will run till we reach the end of the tree
        return succ;
    }
};