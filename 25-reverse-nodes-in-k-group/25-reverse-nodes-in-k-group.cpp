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
    ListNode* ans(ListNode* head,int k,int length)
    {
        
         if(head==NULL)
            return NULL;
     
        if(length<k)
            return head;
        
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* nexti;
        int count=0;
        
        while(curr&&count<k)
        {
            count++;
            nexti=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=nexti;
        }
        
        if(nexti)
            head->next=ans(nexti,k,length-k);
        
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
         int length=0;
         ListNode* t=head;
        while(t!=NULL)
        {
            length++;
            t=t->next;
        }
        
         ListNode* a=ans(head,k,length);
        return a;
       
    }
};