class Solution {
public:
    
    bool isHappy(int n) {
       
        if(n==1)
            return true;
        
        if(n==7)
            return true;
        
        if(n<10)
            return false;
        
        int count=0;
        while(n>0)
        {
            int y=n%10;
            count+=pow(y,2);
            n=n/10;
        }
     
        
        return isHappy(count);
    }
};