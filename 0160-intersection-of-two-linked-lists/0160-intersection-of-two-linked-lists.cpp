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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB==nullptr){
            return nullptr;
        }
        //dummy nodes
        ListNode* l1=headA;
        ListNode* l2=headB;
        
        while(l1!=l2){
            //keep iterating unless they become equal
            //it will also cover the case when there is no intersection as both will point to nullptr at the same time
            l1=l1==nullptr? headB: l1->next;
            //if l1 becomes null, start it again from the head of the other ll
            
            l2=l2==nullptr? headA: l2->next;
            //if l2 becomes nullptr, start traversing again from the head of another node onwards
            
            //there will be a point when after doing this both the dummy pointers will start from equidistant nodes
        }
        return l1;
    }
};