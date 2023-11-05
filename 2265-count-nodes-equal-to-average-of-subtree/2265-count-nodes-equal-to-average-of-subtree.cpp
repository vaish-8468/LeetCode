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
    /***
    
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
    ***/
    
    //OPTIMISED APPROACH
    //TC=O(N) since every node is being visited only once
    int res=0;
    pair<int,int> calcAvg(TreeNode* root){
        if(root==nullptr){
            return{0,0};
            
        }
        //postOrder traversal
        auto leftS=calcAvg(root->left);
        auto rightS=calcAvg(root->right);
        
        //calculate sum of the subtree
        int sum=leftS.first+rightS.first+root->val;
        //count the number of nodes in the subtree
        int count=leftS.second+rightS.second+1;
        
        int avg=sum/count;
        //check if the avag calculated is equal to the node value
        
        if(avg==root->val){
            res++;
        }
        
        return {sum,count}; //return sum and cumber of nodes in the subtree
    }
    
    int averageOfSubtree(TreeNode* root){
        pair<int,int> values=calcAvg(root);
        return res;
        
        
    }
};