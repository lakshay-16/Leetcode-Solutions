class Solution {
public:
    string longestPalindrome(string s) {
        
     string ans="";   
     int maxl=1;
     int len;
        int start=0;
        
        for(int i=0;i<s.length();i++)
        {
            int low=i-1;
            int high=i+1;
            
            while(high<s.length()&&s[i]==s[high])
                high++;
            
            while(low>=0&&s[i]==s[low])
                low--;
            
            
            while(high<s.length()&&low>=0&&s[low]==s[high])
            {
                low--;
                high++;
            }
          
            len=high-low-1;
            if(len>maxl)
            {
                maxl=len;
                start=low+1;
            }
            
        }
        
        
        for(int i=start;i<start+maxl;i++)
        {
            ans+=s[i];
        }
        
        return ans;
    }
};