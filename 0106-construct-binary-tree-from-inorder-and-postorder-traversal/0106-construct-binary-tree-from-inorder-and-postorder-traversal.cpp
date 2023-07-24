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
    
    TreeNode* constructBinaryTree(vector<int>& postorder, vector<int>& inorder, int postStart, int postEnd, int inStart, int inEnd, map<int,int>& mp){
        if(inStart>inEnd or postStart>postEnd){
            //base case
            return nullptr;
        }
        
        int root_val=postorder[postEnd];
        int rootIndex=mp[root_val];
        int numLeftElem=rootIndex-inStart;
        
        TreeNode* root=new TreeNode(root_val);
        
        root->left=constructBinaryTree(postorder,inorder,postStart, postStart+numLeftElem-1,inStart,rootIndex-1,mp);
        
        root->right=constructBinaryTree(postorder,inorder,postStart+numLeftElem, postEnd-1,rootIndex+1,inEnd,mp);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postStart=0;
        int postEnd=postorder.size()-1;
        int inStart=0;
        int inEnd=inorder.size()-1;
        
        map<int,int> mp; //stores the node value with inorder index
        
        for(int i=0;i<=inEnd;i++){
            mp[inorder[i]]=i;
        }
        
        return constructBinaryTree(postorder,inorder,postStart,postEnd,inStart,inEnd,mp);
    }
};