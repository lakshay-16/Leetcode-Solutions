class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int i=0;
        int e=nums.size()-1;
        sort(nums.begin(),nums.end());
        
        while(i<=e)
        {
            int mid=i+(e-i)/2;
            if(nums[mid]==target)
                return mid;
                
            else if(nums[mid]>target)
                e=mid-1;
            
            else
                i=mid+1;
            
        }
        
        
        return -1;
    }
};