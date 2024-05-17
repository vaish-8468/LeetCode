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
    TreeNode* traversalFunc(TreeNode* root, int target){
        if(root==nullptr){
            return nullptr;
        }
        
        //takes care of the special case
        //when parent becomes the target
        //after the removal of the target child
        root->left=traversalFunc(root->left,target);
        root->right=traversalFunc(root->right,target);
        
        if(root->left==nullptr and  root->right==nullptr and root->val==target){
            return nullptr;
        }
      
        
        return root; //otherwise
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        return traversalFunc(root,target);
        
    }
};