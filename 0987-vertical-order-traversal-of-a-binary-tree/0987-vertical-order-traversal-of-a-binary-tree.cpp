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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //we treat the nodes to be placed in a coordinate system with x-axis as it is and origin at root and +y axis towards down
        queue<pair<TreeNode*, pair<int,int>>> que; //stores {node,{x,y}}
        map<int,map<int,multiset<int>>> mp; //maps {x->{y->{node}}}
        
        vector<vector<int>> ans; //stores vertical traversal of trees
        
        que.push({root,{0,0}});
        
        while(!que.empty()){
            auto itr=que.front();  //level order traversal
            que.pop();
            
            TreeNode* node=itr.first;
            int x=itr.second.first;
            int y=itr.second.second;
            
            mp[x][y].insert(node->val);
            if(node->left!=nullptr){
                que.push({node->left,{x-1,y+1}});
            }
            if(node->right!=nullptr){
                que.push({node->right,{x+1,y+1}});
            }
        }
        
        for(auto p:mp){
            vector<int> vertical;
            for(auto q: p.second){
                vertical.insert(vertical.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(vertical);
        }
        
        return ans;
    }
};