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
    //findsthe irghtmost node in the left subtree of the deleted node
    TreeNode* lastRightInLeftSubtree(TreeNode* root){
        if(root->right==nullptr){
            return root;
            //base case whej we reach the leaf node
        }
        return lastRightInLeftSubtree(root->right);
    }
    
    //here root is the deleted node
    TreeNode* relocate(TreeNode* root){
        if(root->left==nullptr){
            return root->right; //if left child doesn't exits for the deletd node simply make connections between root and right child of the deleted node
        }
        else if(!root->right){
            return root->left;
        }
        
        TreeNode* rightChild=root->right;
        TreeNode* lastRight=lastRightInLeftSubtree(root->left); //to find the rightmost node nin the left subtree of deleted node
        lastRight->right=rightChild; //connect the rightmost node of left subtree to the right child of the deleted node
        
        return root->left; //assuming left connections are made
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr){
            return nullptr;
        }
        else if(root->val==key){
            return relocate(root);
        }
        
        TreeNode* temp=root;
        
        while(temp!=nullptr){
          if(temp->val>key){
              //move to the left
              if(temp->left!=nullptr && temp->left->val==key){
                  temp->left=relocate(temp->left); //assuming the connections to be made between root and deleed node's left child
                  break;
              }
              else{
                  temp=temp->left;
              }
          }
            else{///otherwise move to the right
                if(temp->right!=nullptr && temp->right->val==key){
                    //if the right vhild is the node to be deleted
                    temp->right=relocate(temp->right); //make connections with the right vhild of the deleted node
                    //reposition the children of nod eot be deleted
                    break;
                    
                }
                else{
                    //keep traversing
                    temp=temp->right;
                }
            }
        }
        
        return root;
        
    }
};