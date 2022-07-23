/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:  
    Node* flatten(Node* head) {
       
        Node* curr=head,*nexti,*temp;
        
        while(curr)
        {
            
            if(curr->child)
            {
                nexti=curr->next;
                curr->next=curr->child;
                curr->next->prev=curr;
                curr->child=NULL;
                
                temp=curr->next;
                while(temp->next)temp=temp->next;
                temp->next=nexti;
                if(nexti)nexti->prev=temp;
            }
            
            curr=curr->next;
        }
        
        return head;
    }
};