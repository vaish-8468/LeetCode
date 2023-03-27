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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy= new ListNode();
        //it is necessary to declare a dummy variable as we cannot simply modify the original linked list directly
        dummy->next=head;
        ListNode* first=dummy;
        ListNode* second =dummy;
        
      
        for(int i=1;i<=n;i++){
            
        first=first->next;
        
        }
        while(first->next!=NULL ){
            first=first->next;
            second=second->next;
            
        }
        second->next=second->next->next;
        
        return dummy->next;
    }
};