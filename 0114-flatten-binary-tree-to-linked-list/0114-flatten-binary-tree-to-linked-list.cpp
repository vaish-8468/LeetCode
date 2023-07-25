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
    /* key points:
    -The sequence of nodes in the linked list should be the same as that of the preorder traversal of the binary tree.
    -The linked list nodes are the same binary tree nodes. You are not allowed to create extra nodes.
    -The right child of a node points to the next node of the linked list whereas the left child points to NULL.
    
    
    */
    void flatten(TreeNode* root) {
        //using morris method of preorder traversal
        
        TreeNode* currNode= root;
        while(currNode!=nullptr){
            if(currNode->left!=nullptr){
                TreeNode* prevNode=currNode->left;
                //starts from the left child of the root
                
                while(prevNode->right!=nullptr){
                    prevNode=prevNode->right;
                    //moves to the rightmost node of the left subtree
                }
                //connect the right of prev node to the right of the curr node
                prevNode->right=currNode->right;
                
                //disconnect and connect right of curr node to the left of the curr node
                currNode->right=currNode->left;
                
                currNode->left=nullptr;//make the left pointer as null
                
            }
            //move to the right after connecting the right edge
            currNode=currNode->right;
        }
    }
};