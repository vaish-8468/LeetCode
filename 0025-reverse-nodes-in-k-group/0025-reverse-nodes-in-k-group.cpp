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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy =new ListNode();
        dummy->next=head;
        
        ListNode* current=dummy;
        ListNode* prev=dummy;
        
        int count=0;
        //count the number of nodes
        while(current->next!=nullptr){
            count++;
            current=current->next;
        }
        
        //traverse until count is greater than or equal to k
        
        while(count>=k){
            current=prev->next;
            ListNode* next=current->next;
            int j=1;
            //reverse the linked list for every list of length k
            while(j<k){
                current->next=next->next;
                next->next=prev->next;
                prev->next=next;
                next=current->next;
                j++;
        
            }
            count-=k;
            prev=current;
        }
        return dummy->next;
        
    }
};