class Solution {
public:
    int nextGreaterElement(int n) {
        
        string x=to_string(n);
        next_permutation(x.begin(),x.end());
        
        long long int ans=0;
        for(auto y:x)
            ans=ans*10+y-'0';
        
       
        
        return (ans<=n||ans>INT_MAX)?-1:ans;
    }
};