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
    //TC=O(n^2)
//     int maxDiff=INT_MIN;
//     void childTraversal(TreeNode* root, TreeNode* child){
//         if(root==nullptr || child==nullptr){
//             return;
//         }
        
//         maxDiff=max(maxDiff, abs(root->val-child->val));
        
//         childTraversal(root,child->left);
//         childTraversal(root, child->right);
        
//     }
    
    
//     void rootTraversal(TreeNode* root){
//         if(root==nullptr){
//             return;
//         }
        
//         childTraversal(root,root->left);
//         childTraversal(root,root->right);
        
//         rootTraversal(root->left);
//         rootTraversal(root->right);
    
//     }
    int maxAncestorDiff(TreeNode* root) {
        
//         rootTraversal(root);
        
//         return maxDiff;
        
        return solve(root,root->val,root->val);
        
    }
    
    
    //TC=O(n)
    
    int solve(TreeNode* root, int mini, int maxi){
        if(root==nullptr){
            return abs(maxi-mini);
        }
        
        maxi=max(root->val,maxi);
        mini=min(root->val,mini);
        
        //traverse the left path from the root to the left node and similarly right path from the root to the leaf node
        //update the ans with the max difference
        
        int l=solve(root->left, mini,maxi);
        int r=solve(root->right,mini,maxi);
        
        return max(l,r);
        
    }
};