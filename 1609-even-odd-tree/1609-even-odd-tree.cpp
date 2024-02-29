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
    bool isEvenOddTree(TreeNode* root) {
        
        //return false if either the sequence is not strictly increasing
        //or the value is not as per the rules stated
        
        //implementing level order traversal
        
        queue<TreeNode*> que;
        que.push(root);
        int level=0;
        int last;
      
        while(!que.empty()){
            int j=que.size(); //elements in the level
            // cout<<"level"<<j;
            
            if(level%2==0){
                last=INT_MIN;
            }
            else{
                last=INT_MAX;
            }
            
            for (int i=0;i<j;i++){
                TreeNode* node=que.front();
                // cout<<node->val<<" ";
                que.pop();
                
                //rule violation
                if((level%2==0 && (node->val%2==0 || node->val<=last))
                  || (level%2==1 && (node->val%2==1 || node->val>=last))){
                      return false;
                  }

                    last=node->val;
                   
                    if(node->left){
                        que.push(node->left);
                    }
                    if(node->right){
                        que.push(node->right);
                    }
                  }
            level++;
        }
        
                   
        return true;
    }
};