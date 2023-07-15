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
    bool isBalanced(TreeNode* root) {
        return check(root)!=-1;
    }
    
    int check(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        
        int l=check(root->left);
        if(l==-1){ //if any of the node disobeyes the condn, it will not be balanced tree
            return -1;
        }
        int r=check(root->right);
        if(r==-1){
            return -1;
        }
        
        if(abs(r-l)>1){
            return -1; //check the difference in height
        }
        
        return 1+max(l,r); //we are calculating the height and validating balanced tree simultaneously in O(N) time
    }
};