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

    int minDepth(TreeNode* root) {
         if(root==nullptr){
            return 0; //if we reach the end of the tree
        }
        if(root->right==nullptr && root->left==nullptr){ //when we reach the leaf node
            return 1;
        }
        
        int left= root->left==nullptr? INT_MAX : minDepth(root->left);  //if left child is null then take int_max else take its depth
        int right= root->right==nullptr? INT_MAX : minDepth(root->right); //if right child is null then take int_max else take its depth
        
        return 1+min(left,right); //take 1+ minimum of the two traversals and no overflow since we have already mentioned the leaf node condition
    } 
};