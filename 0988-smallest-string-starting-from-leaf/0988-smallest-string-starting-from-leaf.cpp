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
    
    void dfs(TreeNode* root, vector<string>& vec, string s){
        if(root==nullptr){
            return;
        }
        
        
        s=((char)('a'+(root->val)))+s;
        
        //add it to the vector if it is a leaf node
        if(root->left==nullptr and root->right==nullptr){
            if(s.length()!=1){
            vec.push_back(s);
            }
            s="";
        }
        
        dfs(root->left,vec,s);
        dfs(root->right,vec,s);
    }
    string smallestFromLeaf(TreeNode* root) {
        if(root->left==nullptr && root->right==nullptr){
            string str;
            return str+((char)('a'+(root->val)));
            //adding char to the end of the string
        }
        
        //otherwise avoid the the strings of len 1 as the string will contain only the leaf
        vector<string> vec;
        
        //to find all the strings
        dfs(root,vec,"");
        
        
        //to find lexicographically smallest string
        string Min=vec[0];
        for(int i=1;i<vec.size();i++){
            if(Min>vec[i]){
                Min=vec[i];
            }
        }
        
        return Min;
    }
};