class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        
        vector<long long> ans;
        double x=num;
        x=x/3;
        x-=1;
        long long int y=(long long int)x;
        
        if(x-y==0)
        {
            ans.push_back(x);
            ans.push_back(x+1);
            ans.push_back(x+2);
        }
        
        
        return ans;
    }
};