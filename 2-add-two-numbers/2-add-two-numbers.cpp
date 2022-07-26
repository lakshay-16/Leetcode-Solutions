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
        ListNode* g=new ListNode(-1);
        ListNode* ans=g;
        
        ListNode* r1=l1;
        ListNode* r2=l2;
        
        int carry=0;
        
        while(r1&&r2)
        {
            int sum=r1->val+r2->val+carry;
            carry=sum/10;
            int rem=sum%10;
            g->next=new ListNode(rem);
            r1=r1->next;
            r2=r2->next;
            g=g->next;
        }
        
        while(r1)
        {
            int sum=r1->val+carry;
            carry=sum/10;
           int rem=sum%10;
            g->next=new ListNode(rem);
            r1=r1->next;
            g=g->next;
        }
        
         while(r2)
        {
            int sum=r2->val+carry;
            carry=sum/10;
            int rem=sum%10;
            g->next=new ListNode(rem);
            r2=r2->next;
            g=g->next;
        }
        
        if(carry>0)
            g->next=new ListNode(carry);
        
        
        return ans->next;
    }
};