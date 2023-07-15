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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        bool LtoR=true; //initially for 0th level
        
        if(root==nullptr){
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty()){
            int size=que.size();
            vector<int> level(size,0);
            int i=0;
            while(i<size){
                TreeNode* curr=que.front();
                que.pop();
                
                int idx= (LtoR)? i: (size-1-i); //store the elements acc to LtoR variable direction
                i++;
                level[idx]=curr->val;
                
                if(curr->left!=nullptr){
                    que.push(curr->left);
                }
                if(curr->right!=nullptr){
                    que.push(curr->right);
                }
                
            }
            LtoR= !LtoR; //toggle the boolean value after each level
            res.push_back(level);
        }
        
        return res;
        
     
    }
};