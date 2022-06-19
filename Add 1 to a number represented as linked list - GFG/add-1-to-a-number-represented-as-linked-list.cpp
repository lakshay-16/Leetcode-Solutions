// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node* head)
    {
        Node* prev=NULL;
        Node* curr=head;
        Node* nexti;
        
        while(curr)
        {
            nexti=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=nexti;
        }
        
        return prev;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
      Node* t=reverse(head);
        int carry=1;
        Node* ans=new Node(-1);
        Node* a=ans;
      
      while(carry>0&&t)
      {
          int sum=t->data+carry;
          int val=sum%10;
          ans->next=new Node(val);
          
          carry=sum/10;
          t=t->next;
          ans=ans->next;
      }
      
      if(t)
      ans->next=t;
      
      if(carry>0)
      ans->next=new Node(1);
      
      Node* g=reverse(a->next);
      
      return g;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends