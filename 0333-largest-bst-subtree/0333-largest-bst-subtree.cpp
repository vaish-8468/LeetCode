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
class Node{
    public:
    int size;
    int largest; //largest node value in the left subtree
    int smallest; //smallest node value in the right subtree
    
    Node(int size, int MaxVal, int MinVal){
        this->size=size;
        this->largest=MaxVal;
        this->smallest=MinVal;
        
    }
};
class Solution {
public:
    Node largestBST(TreeNode* root){
            //for empty tree
        if(root==nullptr){
            return Node(0,INT_MIN,INT_MAX); //BST of size 0
            //largest will be INT_MIN
            //smallest will be INt_MAx
            //so that further comparisons can be done
        }
        
        auto leftSubtree=largestBST(root->left);
        auto rightSubtree=largestBST(root->right);
        
        
        if(root->val>leftSubtree.largest and root->val<rightSubtree.smallest){
            //if left<node->val<right, then it is a valid BST
            return Node((leftSubtree.size+rightSubtree.size+1), max(root->val,rightSubtree.largest),min(root->val,leftSubtree.smallest));
            
        }
        //otherwise return largest=INT_MAX and smallest=INT_MIN so that it cannot be a valid BST at the parenrt
        
            return Node(max(leftSubtree.size,rightSubtree.size),INT_MAX,INT_MIN);
        
    }
    int largestBSTSubtree(TreeNode* root) {
    return largestBST(root).size;
    }
};