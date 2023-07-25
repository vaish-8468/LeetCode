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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        //we'll use morris method of inorder traversal
        
     
        
        TreeNode* currNode=root;
        
        while(currNode!=nullptr){
            if(currNode->left==nullptr){
                ans.push_back(currNode->val);
                currNode=currNode->right; //since left is null
            }
            else{
                TreeNode* prevNode=currNode->left;
                while(prevNode->right!=nullptr && prevNode->right!=currNode){
                    //while rightnode exists and ihe thread hasn't been created yet
                    //create it and then move to the left
                    prevNode=prevNode->right;
                }
                if(prevNode->right==nullptr){//if thread hasn't been create yet
                    prevNode->right=currNode; //create the thread
                    currNode=currNode->left; //move the curr node to its left
                }
                else{//if the thread already exists
                    prevNode->right=nullptr;
                    ans.push_back(currNode->val);
                    currNode=currNode->right; 
                }//in ordre traversal->  left root right
            }
            
        }
        
        return ans;
    }
};