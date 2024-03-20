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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int count=0;
        ListNode* head1=list1;
        ListNode* head2=list2;
        ListNode* temp2=list2;
        
        while(temp2->next!=nullptr){
            temp2=temp2->next;
        }
        
        while(head1!=nullptr){
            if(count==a-1){
                ListNode* temp=head1;
                int cnt=0;
                while(temp!=nullptr){
                    if(cnt==(b-a+1)){
                        break;
                    }
                    cnt++;
                    temp=temp->next;
                }
                head1->next=head2;
                temp2->next=temp->next;
                
            }
            head1=head1->next;
            count++;
        }
        
        return list1;
    }
};