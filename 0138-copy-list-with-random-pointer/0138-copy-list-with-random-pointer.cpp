/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* iter=head;
        Node* front= head;
        //hint 1, 2 and 3
        //created and interweaved list A->A`->B->B`->C
        while(iter!=nullptr){
            front=iter->next;
            Node* copy= new Node(iter->val);
            iter->next=copy;
            copy->next=front;
            iter=front;   
        }
        iter=head;
        
        //initialized the random pointer of each copied node according to the random pointer of the original list 
        while(iter!=nullptr){
            if(iter->random!=nullptr){
            iter->next->random=iter->random->next;
            }
            iter=iter->next->next;
        }
        
        iter=head;
        
        //to extract the original list and the copied list from the interweaved list
        Node* dummy= new Node(0);
        Node* copy_=dummy;
        while(iter!=nullptr){
            front=iter->next->next;
            copy_->next=iter->next;
            iter->next=front;
            copy_=copy_->next;
            iter=iter->next;
            
        }
        
        return dummy->next;
    }
};