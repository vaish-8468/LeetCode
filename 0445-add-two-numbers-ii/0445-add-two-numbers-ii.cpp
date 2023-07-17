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
     stack<ListNode*> s1;
        stack<ListNode*> s2;  //stack will ensure addition in reverse order
        
        while(l1!=nullptr){
            s1.push(l1);
            l1=l1->next;
        }
        
        while(l2!=nullptr){
            s2.push(l2);
            l2=l2->next;
        }
        
        int sum=0;
        int carry=0;
        ListNode* ans=new ListNode(); //answer node
        
        while(!s1.empty() || !s2.empty()){
            if(!s1.empty()){
                sum+=s1.top()->val;
                s1.pop();
            }
            if(!s2.empty()){
                sum+=s2.top()->val;
                s2.pop();
            }
            
            ans->val=sum%10;
            carry=sum/10;
            ListNode* node=new ListNode(carry); //we'll add ans in reverse order i.e before head of the ans node
            node->next=ans;
            ans=node;
            sum=carry;
        }
        
        return carry==0?ans->next:ans; //handles the corner case if the first digit contains the ans or not i.e carried value
    }
};

//O(100)  TC worst case
//O(100) SC