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
    int total=0;
    void PostOrder(TreeNode* root, string num){
        if(root==nullptr){
            return;
        }
        
        num+=to_string(root->val);
        // PostOrder(root->left,num+=to_string(root->val));
        PostOrder(root->left,num);

        // num=num.substr(0,num.length()-1); //remove
        // PostOrder(root->right,num+=to_string(root->val));
        // num+=to_string(root->val);
        PostOrder(root->right,num);

        if(root->left==nullptr and root->right==nullptr){
            total+=stoi(num);
        }
         cout<<num<<" "<<root->val<<endl;
        
    }
    int sumNumbers(TreeNode* root) {
        if(root->left==nullptr and root->right==nullptr){
            return root->val;
        }
        PostOrder(root,"");
        
        return total;
    }
};