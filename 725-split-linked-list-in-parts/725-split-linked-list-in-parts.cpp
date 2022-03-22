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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int count=0;
        ListNode* temp=head;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        
        
        int extra=count%k;
        int width=count/k;
        ListNode* cur=head;
        vector<ListNode*> ans;
        for(int i=0;i<k;++i)
        {
            ListNode* head=new ListNode(0);
            ListNode* write=head;
            for(int j=0;j<width+(i<extra?1:0);++j)
            {
                write=write->next=new ListNode(cur->val);
                if(cur!=NULL)
                    cur=cur->next;
            }
                
            ans.push_back(head->next);
        }
        
        return ans;
    }
};