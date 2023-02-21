/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
/* 1.Pop the top node from the stack – Top from the stack and insert it into the visited list of nodes.
2. Push all of the child nodes of Top into the stack from right to left as the traversal from the stack will be carried out in reverse order. As a result, correct preorder traversal is achieved.*/

class Solution {
public:
    void function(Node* root, vector<int> &v){
    if(root==nullptr){
        return;
    }
    v.push_back(root->val);
    for(int i=0;i<root->children.size();i++){
        function(root->children[i],v);
    }
}
    vector<int> preorder(Node* root) {
    vector<int> v;
    function(root,v);
    return v;
    }
};