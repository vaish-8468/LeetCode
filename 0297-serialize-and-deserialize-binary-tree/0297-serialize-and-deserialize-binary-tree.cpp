/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr){
            return "";
        }
        //we'll use level order traversal
        queue<TreeNode*> que;
        string s="";
        que.push(root);
        
        
        while(!que.empty()){
            TreeNode* node=que.front();
            que.pop();
            if(node==nullptr){
                s.append("$,");
            }
            else{
            s.append(to_string(node->val)+',');
            }
            
            if(node!=nullptr){
                que.push(node->left); //we'll pusb the nodes irrespective of them being nullptr since we wanna initialize $ also for nullptr
                que.push(node->right);
            }
            
        }
            
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0){
            return nullptr;
        }
        //we'll again use level order to form the tree from scratch
        string s;
        //we'll create a string which will be iterated as object
        stringstream str(data);
        getline(str,s,','); //take the first input till the delimiter is encountered
        
        TreeNode* root=new TreeNode(stoi(s)); //creates a new node and initialize it with (int)s
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty()){
            TreeNode* node=que.front();
            que.pop();
            
            //takes the next obj from the input for initializing left child
            getline(str,s,',');
            
            if(s=="$"){
                node->left=nullptr;
            }
            else{
                TreeNode* leftChild= new TreeNode(stoi(s));
                node->left=leftChild;
                que.push(leftChild);
            }
            
            //takes the next obj from the input for initializing right child
            getline(str,s,',');
            
            if(s=="$"){
                node->right=nullptr;
            }
            else{
                TreeNode* rightChild= new TreeNode(stoi(s));
                node->right=rightChild;
                que.push(rightChild);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));