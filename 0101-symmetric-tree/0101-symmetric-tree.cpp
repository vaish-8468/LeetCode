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
    bool helperfunc(TreeNode* root1, TreeNode* root2){
        if(root1==nullptr || root2==nullptr){
            return root1==root2; //true if   both of them points to true
        }
        return ((root1->val==root2->val) &&  helperfunc(root1->left,root2->right) && helperfunc(root1->right,root2->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        
        return helperfunc(root->left,root->right);
    }
};