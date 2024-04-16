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

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newNode=new(TreeNode);
            newNode->val=val;
            newNode->left=root;
            root=newNode;
            return root;
        }
        TreeNode* node;
        queue<TreeNode*> que;
        que.push(root);
        int level=1;
        while(!que.empty() and level<depth-1){
            int n=que.size();
            
            while(n--){
                node=que.front();
                cout<<"first"<<node->val<<endl;
                que.pop();
                
                if(node->left!=nullptr){
                    que.push(node->left);
                }
                if(node->right!=nullptr){
                    que.push(node->right);
                }
            }
            level++;
        }
        
        //insert the nodes in the curr level
        int n=que.size();
        while(n-- && !que.empty()){
           node=que.front();
            cout<<"second"<<node->val<<endl;
            que.pop();
            if(node->left!=nullptr){
                TreeNode* newNode=new(TreeNode);
                newNode->val=val;
                newNode->left=node->left;
                node->left=newNode;
            }
            else{
                TreeNode* newNode=new(TreeNode);
                newNode->val=val;
                node->left=newNode;
            }
            if(node->right!=nullptr){
                TreeNode* newNode=new(TreeNode);
                newNode->val=val;
                newNode->right=node->right;
                node->right=newNode;
            }
            else{
                TreeNode* newNode=new(TreeNode);
                newNode->val=val;
                node->right=newNode;
            }
            
        }
        
        return root;
        
    }
};