/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* first=head;
        ListNode* second=head;
        int count=0;
        while(second && second->next){
            first=first->next;
            second=second->next->next;
            if(first==second){
                break;
                
            }
            
        }
        if(!(second && second->next)){
            return nullptr;
        }
        while(head!=first){
            head=head->next;
            first=first->next;
        }
        return head;
        
    }
};