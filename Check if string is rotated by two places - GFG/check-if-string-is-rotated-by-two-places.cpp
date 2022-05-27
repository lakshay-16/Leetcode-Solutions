// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    string arotate(string s)
    {
        string g="";
        int n=s.length();
        for(int i=n-2;i<n;i++)
        g+=s[i];
        
        for(int i=n;i>=2;i--)
        s[i]=s[i-2];
        
        for(int i=0;i<2;i++)
        s[i]=g[i];
        
        return s;
    }
    
    string rotate(string s)
    {
        string g="";
        int n=s.length();
        for(int i=0;i<2;i++)
        g+=s[i];
        
        for(int i=2;i<n;i++)
        s[i-2]=s[i];
        
        for(int i=n-2;i<n;i++)
        s[i]=g[i-n+2];
        
        return s;
    }
    
    bool isRotated(string str1, string str2)
    {
        // Your code here
        if(str1.length()<3)
        return true;
        
        string x1=rotate(str1);
        string x2=arotate(str1);
       
        if(str2==x1||str2==x2)
        return true;
        
        return false;
    }

};


// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends