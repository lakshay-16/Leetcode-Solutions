// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    stack<int> s;
    unordered_map<int,int> m;
    int mini=INT_MAX;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if(s.empty())
           return -1;
           
           return mini;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
           if(s.empty())
           return -1;
           
           int x=s.top();
           
           if(s.top()!=mini)
           s.pop();
           
           else
           {
               s.pop();
               stack<int> p;
               mini=INT_MAX;
               while(!s.empty())
               {
                   mini=min(mini,s.top());
                   p.push(s.top());
                   s.pop();
               }
               
               while(!p.empty())
               {
                   s.push(p.top());
                   p.pop();
               }
           }
           
           return x;
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
           mini=min(mini,x);
           s.push(x);
       }
};

// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends