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
    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr!=nullptr){
        ListNode* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
       
            
        }
        return prev;
        
    }
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return true;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        
        
        //for finding the middle of the linked list
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            //since we want the first middle of the linked list if hte no. of nodes are even
            //and middle of the linked list if the no. of nodes are odd, hence fast becomes nullptr
            slow=slow->next;
            fast=fast->next->next;
            
            
        }
        
        ListNode* dummy=head;
        //reverse the half portion of the linked list
        slow=reverse(slow->next);
        
        //traverse simultaneously and compare the values
        while(slow!=nullptr){
            if(slow->val!=dummy->val){
                return false;
            }
            dummy=dummy->next;
            slow=slow->next;
        }
        return true;
        
        
    }
};

