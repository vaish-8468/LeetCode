/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//https://www.youtube.com/watch?v=1PMjfQl_UVQ
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> mp;
    
    vector<int> ds;
    void BFS(TreeNode* root, int k){
        queue<TreeNode*> que;
        que.push(root);
        int level=0;
        set<TreeNode*> st; //keep a record of the visited parent so that it doesn't repeats
        st.insert(root);
        while(!que.empty()){
            int size=que.size();
            if(level==k){ //when level becomes equal to k then the queue will store only the nodes of that level
                break;
            }
            while(size--){
               
                TreeNode* curr=que.front();
                que.pop();
                cout<<curr->val;
              
                
                if(curr->left!=nullptr && !st.count(curr->left)){ //if left node is not null and it hasn't been visited
                    que.push(curr->left); //push it in the queue 
                    st.insert(curr->left); //mark it as visited
                }
                if(curr->right!=nullptr && !st.count(curr->right)){
                    que.push(curr->right);
                    st.insert(curr->right);
                }
                if(mp.find(curr)!=mp.end() && !st.count(mp[curr])){ //if parent of that node is not null and it hasn't been counted or visited
                    que.push(mp[curr]); //push it in the queue
                    st.insert(mp[curr]); //mark it as visited
                }
                
            }
            cout<<endl;
            level++;
        }
        while(!que.empty()){ //push_back nodes of that level in the vector
            ds.push_back(que.front()->val);
            que.pop();
        }
        
    }
    void DFS(TreeNode* root){
     
        if(root==nullptr){
            return;
        }
        if(root->left!=nullptr){
            mp[root->left]=root; //store paret of each node
            DFS(root->left);
        }
         if(root->right!=nullptr){
            mp[root->right]=root; //store parent of each node in a map
            DFS(root->right);
        }
   
        
   
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==nullptr){
            return ds;
        }
        DFS(root); //make the tree undirected by making a directed edge(reln) between child node and parent node
        BFS(target,k); //traverse in BFS order to store all the nodes at level k
        
        
        return ds;
        
        
        
    }
};