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
class BSTIterator {
public:
    stack<TreeNode*> st; //will contain/store the elments traversed
    BSTIterator(TreeNode* root) {
        push(root); //just pushes the first root of the tree
    }
    
    int next() {
        //since the next call is always valid hence we won't keep a condition for checking its existence
        TreeNode* top= st.top();
        st.pop();
              //insert the right child first
        push(top->right);
        return top->val; //then return the next element
        
    }
    
    bool hasNext() {
        return st.empty()?false:true;
        
    }
    
    void push(TreeNode* node){
        //push all the left child of the node till its extreme left
        while(node!=nullptr){
            st.push(node);
            node=node->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */