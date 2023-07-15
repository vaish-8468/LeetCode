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
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        maxSumPath(root,maxSum);
        return maxSum;
    }
    
    int maxSumPath(TreeNode* root, int& maxSum){
        if(root==nullptr){
            return 0;
        }
        
        int l=max(0, maxSumPath(root->left,maxSum)); //ensure no -ve sum is counted
        int r=max(0,maxSumPath(root->right,maxSum));
        
        maxSum=max(maxSum, root->val+l+r); //updates the maxSum
        
        return root->val+max(l,r); //return the maximum contribution made by left or right subtree
    }
};