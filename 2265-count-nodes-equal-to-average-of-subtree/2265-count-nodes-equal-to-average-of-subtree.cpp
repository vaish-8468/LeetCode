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
    
    
    //BRUTE FORCE
    //for every node, calculate the avg of it's subtree and 
    //check if it is equal to the avg calculated
    //define a seperate function which calculates sum of the subtree
    //TC=O(n^2)
    
    int calcSum(TreeNode* root, int &countNodes){
        if(root==nullptr){
            return 0;
        }
        countNodes++;
        int leftSum=calcSum(root->left,countNodes);
        int rightSum=calcSum(root->right,countNodes);
        
        return (leftSum+rightSum+root->val);
    }
    int res=0; //to store the number of nodes whose avg sum of subtree is equal to it's node value
    void preOrder(TreeNode* root){
        if(root==nullptr){
            return;
        }
        int countNodes=0;
        int Sum=calcSum(root,countNodes);
        if(root->val==Sum/countNodes){
            res++;
        }
        preOrder(root->left);
        preOrder(root->right);
        
       
    }
    
    int averageOfSubtree(TreeNode* root) {
        preOrder(root);
        return res;
    }
    
    
//     int averageOfSubtree(TreeNode* root){
        
//     }
};