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
        if(root==nullptr || root==p || root==q){
            return root; //wither we reach the leaf node or the node p or q then simply return root
        }
        
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        
        if(left==nullptr){
            return right; //if left returned value is null
        }
        else if(right==nullptr){
            return left; //if right returned value is null
        }
        else{
            return root; //when both left and right are not null then that will be the lowest ancestor
        }
    }
};