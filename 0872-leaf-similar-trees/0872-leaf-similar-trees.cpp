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
    void findLeafNodeSubsequence(TreeNode* root, vector<int>& ans){
        if(root->left==nullptr and root->right==nullptr){
            ans.push_back(root->val);
            return;
        }
        
        if(root->left!=nullptr){
            findLeafNodeSubsequence(root->left,ans);
        }
        
        if(root->right!=nullptr){
            findLeafNodeSubsequence(root->right,ans);
        }
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> Tree1;
        vector<int> Tree2;
        
        findLeafNodeSubsequence(root1,Tree1);
        findLeafNodeSubsequence(root2,Tree2);
        
        if(Tree1==Tree2){
            return true;
        }
        else{
            
            return false;
        }
    }
};