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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        ListNode* list=head;
        int count=0;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        int mid;
        if(count%2==0){
            mid=(count/2);
        }
        else{
            mid=(count+1)/2;
        }
        while(list!=nullptr){
            if(count==mid){
                break;
            }
            count--;
            list=list->next;
        }
        return list;
    }
};