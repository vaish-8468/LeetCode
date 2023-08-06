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
    TreeNode* constructBST(vector<int>& preorder, int& itr, int upperBound){
        //base case
        //if array element is greater than upperbound then it can be set in the current subtree
        //else if all the elements of preorder are traversed
        if(itr==preorder.size() || preorder[itr]>upperBound ){
            return nullptr;
        
        }
        TreeNode* node=new TreeNode(preorder[itr++]);
        //create a new node from the element
        //update the upperbound for left subtree to be the current subtree root node value
        //adds node if it is found to be less than the current node
        node->left=constructBST(preorder,itr,node->val);
        //pass over the same upperbound and adds node if it is found to lie within the specified upperbound
        node->right=constructBST(preorder,itr,upperBound);
        
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int upperBound=INT_MAX;
        int itr=0;
        return constructBST(preorder,itr,upperBound);
        
    }
};