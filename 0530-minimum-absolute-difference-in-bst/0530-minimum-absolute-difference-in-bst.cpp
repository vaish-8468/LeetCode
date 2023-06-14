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
    void traverse(TreeNode* root, TreeNode* &prev, int &diff){
        //INORDER TRAVERSAL
        if(root==nullptr){
            return;
        }
        traverse(root->left,prev, diff);
        
        if(prev!=nullptr){ //while backtracking, if prev is not nullptr i.e there is some value assigned to prev pointer
            diff=min(diff, abs(root->val-prev->val));  ///hence we'll calclate the difference
        }
        prev=root; // after every recursive call, we'll keep modifying tjhe prev pointer
    
        traverse(root->right,prev, diff);
        
    }
    
    //intutition: find the largest and second largest element in the tree and return their difference
    int getMinimumDifference(TreeNode* root) {
        TreeNode* prev=nullptr; 
        
        //we'll maintain prev pointer which will store the last element visited while backtracking
        //since we know that tyhe minimum diffrenec can be calculated only by taking a differenec of two adjacent nodes
        
        int diff=INT_MAX;
        
        
        traverse(root, prev, diff); //inorder returns array in sorted increasing order
    
        
        return diff;
    }
};