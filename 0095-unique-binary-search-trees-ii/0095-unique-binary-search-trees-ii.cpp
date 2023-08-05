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
    map<pair<int,int>,vector<TreeNode*>> mp;
    vector<TreeNode*> allpossibleBST(int start, int end){
        //base case
        if(start>end){
            return {nullptr};
        }
        if(start==end){//when single root is preent in bST
            TreeNode* root=new TreeNode(start);
            return mp[{start,end}]={root}; //we'll memoize it
        }
        
        //otherwise
        //we'll give chances to all i
        vector<TreeNode*> ans;
        for(int i=start;i<=end;i++){
            vector<TreeNode*> leftSubtree=allpossibleBST(start,i-1);
            vector<TreeNode*> rightSubtree=allpossibleBST(i+1,end);
            
            for(auto& leftnode: leftSubtree){
                for(auto& rightnode: rightSubtree){
                    TreeNode* root= new TreeNode(i);
                    
                    root->left=leftnode;
                    root->right=rightnode;
                    ans.push_back(root);
                }
            }
        }
        return mp[{start,end}]=ans;
        
        //pair and generate all different types of possibilities for left Subtree and Rightb Subtree
        
        
    }
    vector<TreeNode*> generateTrees(int n) {
     
       return allpossibleBST(1,n);
        

    }
};