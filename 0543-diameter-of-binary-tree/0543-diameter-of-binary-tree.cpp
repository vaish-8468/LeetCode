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
    int validate(TreeNode* root, int& max_height){
        if(root==nullptr){
            return 0;
        }
        
        int l=validate(root->left,max_height);
        int r=validate(root->right, max_height);
        
        max_height=max(max_height,l+r); //calculting diameter as a sum of left height and right height
        
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int max_height=0;
        validate(root,max_height);
        return max_height;
    }
};