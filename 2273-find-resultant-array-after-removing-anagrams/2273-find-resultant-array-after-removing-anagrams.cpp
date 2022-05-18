class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        
        vector<string> ans;
       
        
        string prev=words[0];
        ans.push_back(prev);
        for(int i=1;i<words.size();i++)
        {
            string s1=prev;
            string s2=words[i];
            
            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());
            
            if(s1==s2)
                continue;
            
            else
            {
                prev=words[i];
                ans.push_back(prev);
            }
            
        }
        
        
        return ans;
    }
};