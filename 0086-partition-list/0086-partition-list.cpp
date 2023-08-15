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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallList= new ListNode();
        ListNode* largeList= new ListNode();
        
        //we formed two seperate list
        //one for small
        //other for large
        //we concatenated all the nodes less than x to the smaller value list
        //equal or large value to the larger list
        //at the end, we connected the end of smaller list to the start of the larger list and returned the head of the smaller list
        
        ListNode* smallptr=smallList;
        ListNode* largeptr=largeList;
        
        while(head!=nullptr){
            if(head->val<x){
                smallptr->next=head;
                smallptr=smallptr->next;
            }
            else{
                largeptr->next=head;
                largeptr=largeptr->next;
            }
            
            head=head->next;
        }
        
        smallptr->next=largeList->next;
        largeptr->next=nullptr;
        
        return smallList->next;
    }
};