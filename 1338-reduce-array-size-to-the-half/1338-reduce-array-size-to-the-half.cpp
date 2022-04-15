class Solution {
public:
    static bool comp(pair<int,int>&a,pair<int,int> &b)
    {
        return a.second<b.second;
    }
    
    int minSetSize(vector<int>& arr) {
        
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++)
            m[arr[i]]++;
        
        
        vector<pair<int,int>> a;
        for(auto x:m)
            a.push_back(x);
        
        sort(a.begin(),a.end(),comp);
        
        
        int count=0;
        int sum=0;
        for(int i=a.size()-1;i>=0;i--)
        {
            sum+=a[i].second;
            count++;
            
            if(sum>=arr.size()/2)
                break;
        }
        
        
        return count;
        
    }
};