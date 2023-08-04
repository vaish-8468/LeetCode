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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr){
            return new TreeNode(val);
        }
        TreeNode* temp=root;
        while(temp!=nullptr){
            if(temp->val>val){
                //traverse till the last node
                if(temp->left!=nullptr){
                    temp=temp->left;
                }
                else{
                    //otherwise make it the leaf node
                    TreeNode* node=new TreeNode(val);
                    temp->left=node;
                    break;
                }
            }
            else{//move to the right if node value is less than the given value
                if(temp->right!=nullptr){
                    temp=temp->right;
                }
                else{
                    //make it the last node
                    TreeNode* node=new TreeNode(val);
                    temp->right=node;
                    break;
                }
            }
        }
        return root;
    }
};