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
    
    int length(ListNode* head)
    {
        int count=0;
        while(head)
        {
            count++;
            head=head->next;
        }
        
        return count;
    }
    
    
    ListNode* swapNodes(ListNode* head, int k) {
        
        
        int prev;
        ListNode* pre;
        ListNode* temp=head;
        
        int len=length(temp);        
        int next=len-k+1;
        
        if(k>next)
        {
            int x=k;
            k=next;
            next=x;
        }
        
        temp=head;
        int count=0;
        
        
        while(temp)
        {
            count++;
            
            if(count==k)
            {
                prev=temp->val;
                pre=temp;
            }
            
            
            if(count==next)
                break;
            
            temp=temp->next;
        }
        
        
        pre->val=temp->val;
        temp->val=prev;
        
        
        return head;
        
    }
};