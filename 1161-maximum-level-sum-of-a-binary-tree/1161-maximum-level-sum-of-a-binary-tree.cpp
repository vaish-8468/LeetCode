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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int maxsum_=INT_MIN;
        int level=1;
        int anslevel=0;
        
        q.push(root);
        
        while(!q.empty()){  //implementing BFS
            
            int sum_=0;
            int n=q.size(); //keeps a record of the number of elemts in a level
            
            while(n--){ //traversing all elements of curr level
                
                TreeNode* curr=q.front();
                q.pop();
                sum_+=curr->val; //calculate the ;evel sum
                
                if(curr->left){  //push left child
                    q.push(curr->left);
                }
                if(curr->right){ //push right child
                    q.push(curr->right);
                }
            }
            if(sum_>maxsum_){
                anslevel=level; //if the sum of the level is greater than maxsum of level till now, update the level and maxsum
                maxsum_=sum_;
            }
            level++;
        }
        
        return anslevel;
    }
};