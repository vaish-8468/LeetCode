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
    void inOrder(TreeNode* root, int low, int high, int& Sum){
        if(root==nullptr){
            return ;
        }
        
        inOrder(root->left,low,high,Sum);
        //check the range and add it to the sum
        int value=root->val;
        if(value>=low and value<=high){
            Sum+=value;
        }
        inOrder(root->right,low,high,Sum);
        
        
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        //inorder traversal gives increasing order subsequence
        int Sum=0;
        
        inOrder(root,low,high,Sum);
        
        return Sum;
        
        
    }
};