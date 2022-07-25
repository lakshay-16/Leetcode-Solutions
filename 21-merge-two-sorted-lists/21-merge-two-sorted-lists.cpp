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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* g=new ListNode(-1);
        ListNode* ans=g;
        
        while(list1&&list2)
        {
            if(list1->val<=list2->val)
            {g->next=list1;
            list1=list1->next;
             g=g->next;
            }
             
            else
            {
             g->next=list2;
                list2=list2->next;
                g=g->next;
            }
        }
        
        if(list1)
            g->next=list1;
        
        if(list2)
            g->next=list2;
        
        return ans->next;
    }
};