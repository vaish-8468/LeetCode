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
    class BSTIterator{
        public:
        stack<TreeNode*> st;
        bool Reverse=true; //initially
        BSTIterator(TreeNode* root, bool reverse){
          
            Reverse=reverse;
              push(root);
        }
        /** @return whether we have a next smallest number */
    bool hasNext() {
        return st.empty();
    }
        
        int next(){
            TreeNode* top=st.top();
            st.pop();
            //push the right child for normal BSTIterator and left child for reverse
            if(!Reverse){
                push(top->right);
            }
            else{
                push(top->left);
            }
            return top->val;
        }
private:
        
        void push(TreeNode* node){
            while(node!=nullptr){
                st.push(node);
                if(Reverse==true){
                    node=node->right; //reverse of original BSTIterator, to fetch data in descending order
                }
                else{
                    node=node->left;
                }
            }
        }
    };
    class Solution {
    public:
    bool findTarget(TreeNode* root, int k) {
        if(root==nullptr){
            return false;
            
        }
        //define two pointers
        BSTIterator Next(root,false);//Inorder
        BSTIterator Before(root,true);//reverse Inorder
        
        int i=Next.next(); //smallest element
        int j=Before.next();//largest element
        
        while(i<j){
            if(i+j==k){
                return true;
            }
            if(i+j<k){
                i=Next.next();
            }
            else{
                j=Before.next();
            }
        }
        return false; //otherwise
    }
};