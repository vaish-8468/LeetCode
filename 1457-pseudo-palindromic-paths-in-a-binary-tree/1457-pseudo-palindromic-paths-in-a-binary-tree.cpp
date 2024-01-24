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
    int count=0;
    void DFS(TreeNode* root, int (&arr)[9]){
        if(root==nullptr){
            return;
        }
        if(root->left==nullptr and root->right==nullptr){
            int flag=0;
            arr[root->val-1]++;
            for(int i=0;i<9;i++){
                if(arr[i]%2!=0){
                    flag++;
                }
            }
            if(flag<=1){
                count++;
            }
            arr[root->val-1]--;
            return;
        }
        arr[root->val-1]++;
        DFS(root->left,arr);
        DFS(root->right,arr);
        arr[root->val-1]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int arr[9]={0};
        DFS(root,arr);
        return count;
    }
};