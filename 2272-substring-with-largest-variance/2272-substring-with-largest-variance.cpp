class Solution {
public:
    int largestVariance(string s) {
        int n=s.length();
        int res=0;
        
        for(char p='a';p<='z';p++)
        {
            for(char q='a';q<='z';q++)
            {
                int pcount=0;
                int qcount=0;
                
                bool flag=false;
                
                for(auto x:s)
                {
                    if(x==p) pcount++;
                    if(x==q) qcount++;
                    
                    if(qcount>0)
                        res=max(res,pcount-qcount);
                    
                    else if(qcount==0&&flag)
                        res=max(res,pcount-qcount-1);
                    
                    if(qcount>pcount)
                    {
                        pcount=qcount=0;
                        
                        flag=true;
                    }
                        
                }
            }
        }
    
    return res;
    }
};