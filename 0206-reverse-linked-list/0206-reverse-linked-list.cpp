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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        ListNode* rev_list=nullptr;
       
        while(head!=nullptr){
            ListNode* list=head;
            head=head->next;
            list->next=rev_list;
            rev_list=list;
            
            
            
            
        }
        return rev_list;

        
    }
};