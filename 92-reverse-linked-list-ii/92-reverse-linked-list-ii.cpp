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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        stack<int> st;
        
        ListNode* temp=head;
        int count=1;
        while(temp)
        {
            if(count>=left&&count<=right)
                st.push(temp->val);
            
            temp=temp->next;
            count++;
        }
        
        
        temp=head;
        count=1;
        while(temp)
        {
            if(count>=left&&count<=right)
            {
                temp->val=st.top();
                st.pop();
            }
            
            temp=temp->next;
            count++;
        }
        
        return head;
    }
};