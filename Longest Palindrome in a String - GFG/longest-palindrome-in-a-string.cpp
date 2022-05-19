// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string str) {
        // code here
        string ans="";
        int ml=1;
        int start=0;
        int len;
        
        for(int i=0;i<str.length();i++)
        {
            int low=i-1;
            int high=i+1;
            
            while(high<str.length()&&str[i]==str[high])
            high++;
            
            while(low>=0&&str[i]==str[low])
            low--;
            
            while(low>=0&&high<str.length()&&str[low]==str[high])
            {
                low--;
                high++;
            }
            
            len=high-low-1;
            
            if(len>ml)
            {
                ml=len;
                start=low+1;
            }
            
        }
        
        for(int i=start;i<=start+ml-1;i++)
        ans+=str[i];
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends