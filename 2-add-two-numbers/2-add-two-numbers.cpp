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
          ListNode* rf=l1;
        ListNode* rs=l2;
        
        ListNode* ans=new ListNode(-1);
        ListNode* r=ans;
        int sum=0;
        int carry=0;
        while(rf!=NULL&&rs!=NULL)
        {
            
         sum=rf->val+rs->val;   
            int node=(sum+carry)%10;
            ans->next=new ListNode(node);
            ans=ans->next;
            
            if(sum+carry>9)
            carry=(sum+carry)/10;
            
            else
            carry=0;
            
            rf=rf->next;
            rs=rs->next;
        }
        
        if(rs==NULL&&rf==NULL&&carry>0)
        ans->next=new ListNode(carry);
        
        
       if(rs==NULL&&rf!=NULL)
       {
          while(carry>0&&rf!=NULL)
          {
           ans->next=new ListNode((rf->val+carry)%10);
           carry=(rf->val+carry)/10;
           ans=ans->next;
           rf=rf->next;
          }
       
       if(carry>0&&rf==NULL)
       ans->next=new ListNode(carry);
       
       else
       ans->next=rf;
       }
       
       if(rf==NULL&&rs!=NULL)
       {
             while(carry>0&&rs!=NULL)
          {
           ans->next=new ListNode((rs->val+carry)%10);
           carry=(rs->val+carry)/10;
           ans=ans->next;
           rs=rs->next;
          }
       
       if(rs==NULL&&carry>0)
       ans->next=new ListNode(carry);
       
       else
       ans->next=rs;
       }
        
      
        
        return r->next;
    }
};