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
    int numComponents(ListNode* head, vector<int>& nums) {
     unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        m[nums[i]]++;
        
        int count=0;
        while(head!=NULL)
        {
            if(m.find(head->val)!=m.end())
            {
                while(head!=NULL&&m.find(head->val)!=m.end())
                    head=head->next;
                
                count++;
            }
            
            if(head!=NULL)
                head=head->next;
            
        }
            
         return count;   
    }
};