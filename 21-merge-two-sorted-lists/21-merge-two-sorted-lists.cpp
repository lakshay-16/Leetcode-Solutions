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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
          if(l1==NULL)
            return l2;
        
        if(l2==NULL)
            return l1;
        
        ListNode* g=new ListNode(-1);
        ListNode* ans=g;
        
        while(l1&&l2)
        {
            if(l1->val<=l2->val)
            { g->next=l1;
            l1=l1->next;
            }
            
            else
            {
                g->next=l2;
                l2=l2->next;
            }
            
            g=g->next;   
        }
        
        
        if(l1)
            g->next=l1;
        
        if(l2)
            g->next=l2;
        
        return ans->next;
    }
};