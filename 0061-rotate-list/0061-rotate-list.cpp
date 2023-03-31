/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr || k==0){
            return head;
        }
        ListNode* temp=head;
        int count=1;
        while(temp->next!=nullptr){
            ++count;
            temp=temp->next;
        }
        //connect the last node to the first node such that a circular linked list is created
        temp->next=head;
        k=k%count;
            //reduce k if k>length of the ll
        k=count-k;
        //run a loop for k=length-k starting from the head and break the link of the final node
    
        while(k>0){
            temp=temp->next;
            k--;
        }
        //before assigning the next to nullptr, store the new head and make the next of the last node as nullptr
        head= temp->next;
        temp->next=nullptr;
        return head;
        
        
        
    }
};