class Solution {
public:
    string minimizeResult(string expression) {
        int small=INT_MAX;
        int left=-1;
        int right=-1;
        int length;
        int n=expression.size();
        int plus;
        
        for(int i=0;i<n;i++)
        {
            if(expression[i]=='+')
            {
                plus=i;
                break;
            }
        }
        
        
        for(int i=0;i<plus;i++)
        {
            int k=1;
            for(int j=plus+1;j<n;j++)
            {
                int n1=1;
                string n1str=expression.substr(0,i);
                if(n1str.length()>0)
                    n1=stoi(n1str);
                
            string n2str=expression.substr(i,plus);
                int n2=stoi(n2str);
                
                string n3str=expression.substr(plus+1,k);
                int n3=stoi(n3str);
                k++;
                
                string n4str= expression.substr(j+1);
                int n4=1;
                if(n4str.length()>0)
                n4=stoi(n4str);
                
                
                int ans=n1*(n2+n3)*n4;
                if(ans<small)
                {
                     left=i;
                     right=j+1;
                    small=ans;
                 length=plus+k-i;
                }
                
            }
        }
       
        string sol="";
        sol+=expression.substr(0,left);
        sol+="(";
        sol+=expression.substr(left,length);
        sol+=")";
        sol+=expression.substr(right);
        
        return sol;
    }
};