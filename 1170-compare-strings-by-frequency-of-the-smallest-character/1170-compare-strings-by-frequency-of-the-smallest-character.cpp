class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        
        vector<int> ans;
        vector<int> g1;
        vector<int> g2;
        
        
        for(int i=0;i<queries.size();i++)
        {unordered_map<int,int> m1;
         int x=INT_MAX;
            for(int j=0;j<queries[i].length();j++)
            {m1[queries[i][j]-'a']++;
            x=min(x,queries[i][j]-'a');
            }
         
         g1.push_back(m1[x]);
        }
        
         for(int i=0;i<words.size();i++)
        {unordered_map<int,int> m1;
         int x=INT_MAX;
            for(int j=0;j<words[i].length();j++)
            {m1[words[i][j]-'a']++;
            x=min(x,words[i][j]-'a');
            }
         
         g2.push_back(m1[x]);
        }
        
        for(int i=0;i<g1.size();i++)
        {
            int count=0;
            for(int j=0;j<g2.size();j++)
                if(g2[j]>g1[i])
                    count++;
            
            
            ans.push_back(count);
        }
        
        
        
        return ans;
    }
};