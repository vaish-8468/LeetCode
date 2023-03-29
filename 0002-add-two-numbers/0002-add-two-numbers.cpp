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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();
        ListNode* temp =dummy;
        int sum=0;
        int carry=0;
        if(l1==nullptr){
            return l2;
        }
        if(l2==nullptr){
            return l1;
        }
        while(l1!=nullptr || l2!=nullptr || carry!=0){
            //OR cond is used such that if the lengths are not equal the loop doesn't fails unnecessarily
            sum=0;
            if(l1!=nullptr){
            sum+=l1->val;
            l1=l1->next;
            }
            if(l2!=nullptr){
            sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            
            //declare and initialize a new node to store the sums and traverse it with temp pointer
            ListNode* store=new ListNode(sum%10);
            temp->next=store;
            temp=temp->next;
            
            
        }
        return dummy->next;
        //since the dummy node is insitialized to temp and temp starts to store from temp->next onwards
    }
};