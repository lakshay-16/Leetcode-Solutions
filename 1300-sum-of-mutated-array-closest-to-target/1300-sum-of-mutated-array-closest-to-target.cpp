class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        
        sort(arr.begin(),arr.end());
        int n=arr.size();
        
        int dif=INT_MAX;
        int ans;
        
        int i=0;
        int e=arr[n-1];
        
        while(i<=e)
        {
            int mid=i+(e-i)/2;
            
            int sum=0;
            for(int i=0;i<n;i++)
            {
                if(mid<=arr[i])
                    sum+=mid;
                
                else
                    sum+=arr[i];
            }
            
            
            if(sum==target)
            {
                ans=mid;
                break;
            }
            
            int d=abs(sum-target);
            if(d<=dif)
            {
                if(d==dif)
                ans=min(ans,mid);
                
                else
                {
                    dif=d;
                    ans=mid;
                }
            }
            
            
            if(sum>target)
                e=mid-1;
            
            else
                i=mid+1;
        }
        
        return ans;
    }
};