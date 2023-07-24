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
    //returns the root of the constructed tree
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preStart=0, inStart=0;
        int preEnd=preorder.size()-1, inEnd=inorder.size()-1;
        
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        
        return constructBinaryTree(preorder,inorder,preStart,preEnd,inStart,inEnd,mp);
    }
    
    TreeNode* constructBinaryTree(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, map<int,int>& mp){
        
    //base case
        if(preStart>preEnd or inStart>inEnd){
            return nullptr;
        }
        
        int root_val=preorder[preStart];
        TreeNode* root=new TreeNode(root_val);
        
        int rootIndex=mp[root_val]; //finds the index of the root element
        int leftSubtreeElemCount=rootIndex-inStart; //finds the number of elements in left subtree
        
        root->left=constructBinaryTree(preorder,inorder,preStart+1,preStart+leftSubtreeElemCount,inStart,rootIndex-1,mp);
        
        root->right=constructBinaryTree(preorder,inorder,preStart+leftSubtreeElemCount+1,preEnd,rootIndex+1,inEnd,mp);
        
        return root;
       
        
    }
};