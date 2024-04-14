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
    int Sum=0;
    void PostOrder(TreeNode* root,TreeNode* prev){
        if(root==nullptr){
            return;
        }
        
        PostOrder(root->left,root);
        PostOrder(root->right,root);
        
        if(root->left==nullptr and root->right==nullptr and prev!=nullptr and  prev->left==root){
            Sum+=root->val;
        }
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
    if(root->left==nullptr and root->right==nullptr){
        return Sum;
    }
        PostOrder(root,nullptr);
        return Sum;
    }
};