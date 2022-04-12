class Solution {
public:
    
    static bool comp(pair<char,int> &a,pair<char,int> &b)
    {   return a.second<b.second;
}
    
    string customSortString(string order, string s) {
     unordered_map<char,int> m;
        for(int i=0;i<order.length();i++)
            m[order[i]]=i;
        
        
        vector<pair<char,int>> x;
        string first="";
        string second="";
        
        for(int i=0;i<s.length();i++)
        {
            if(m.find(s[i])!=m.end())
            x.push_back({s[i],m[s[i]]});    
            
            else
                second+=s[i];
        }
        
        sort(x.begin(),x.end(),comp);
        
        for(auto g:x)
            first+=g.first;
        
        return first+second;
    }
};