#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector <int>> ans;
        vector<int> ans1;
        if (!root){
            return ans;
        }
        
    
        queue<TreeNode*> customQ;
        customQ.push(root);
        
        while( !customQ.empty()){
            int level=customQ.size();
            
            for (int i=0;i<level;i++){
                
            
            TreeNode* rootnode=customQ.front();
            customQ.pop();
            ans1.push_back(rootnode->val);
            
            
            if (rootnode->left){
                customQ.push(rootnode->left);
                
            }
            if (rootnode->right){
                customQ.push(rootnode->right);
                
            }
            }
            
            ans.push_back(ans1);
            ans1.clear();
        
        }
        
        return ans;
    
        }
    
};