class Solution {
public:
    
    static bool comp(pair<string,int> &a,pair<string,int> &b)
    {
        if(a.first.length()==b.first.length())
            return a.second<b.second;
        
        return a.first.length()<b.first.length();
    }
    
    string arrangeWords(string text) {
        
        vector<string> g;
        vector<pair<string,int>> m;
        string ans="";
        for(int i=0;i<text.length();i++)
        {
            if(text[i]==' ')
            {
                g.push_back(ans);
                ans="";
                continue;
            }
            
            ans+=text[i];
        }
        
        g.push_back(ans);
        
        
        
        for(int i=0;i<g.size();i++)
        {g[i][0]=tolower(g[i][0]);
            m.push_back({g[i],i});
        }
        
        sort(m.begin(),m.end(),comp);
        
        string x="";
        
        for(int i=0;i<m.size();i++)
        {
            x+=m[i].first;
            
            if(i==m.size()-1)
                continue;
            
            x+=" ";
        }
        
        x[0]=toupper(x[0]);
        
        return x;
        
    }
};