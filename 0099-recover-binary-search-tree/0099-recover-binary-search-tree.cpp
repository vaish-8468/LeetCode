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
         TreeNode* prev=new TreeNode(INT_MIN); //initially starting from INT MIN
    TreeNode* middle= nullptr;
    TreeNode* first= nullptr;
    TreeNode* last=nullptr;
    void InOrderTraversal(TreeNode* node){
        if(node==nullptr){
            return; //base case
        }
        InOrderTraversal(node->left);
        
        if(prev!=nullptr && prev->val>node->val){
            //if curr node value is smaller than previous node value
            if(first==nullptr){
                //if it is the first occurence of violation
                first=prev;
                middle=node;
                
            }
            else{
                //second violation since first is not nullptr
                last=node;
            }
        }
        
        prev=node;
        InOrderTraversal(node->right);
    }
    void recoverTree(TreeNode* root) {
        if(root==nullptr){
            return;
        }
   
        InOrderTraversal(root);
        if(first and last){
            //are true
            //swap them
            swap(first->val,last->val);
        }
        else if(first and middle){
            //are true
            //only one violation occured
            swap(first->val,middle->val);
        }
    }
};