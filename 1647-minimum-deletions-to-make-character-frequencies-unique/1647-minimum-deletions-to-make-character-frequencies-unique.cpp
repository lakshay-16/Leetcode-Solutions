class Solution {
public:
    int minDeletions(string s) {
        
        vector<int> freq(26,0);
        for(int i=0;i<s.length();i++)
            freq[s[i]-'a']++;
        
        int ans=0;
        unordered_set<int> f;
        
        for(int i=0;i<26;i++)
        {
            while(freq[i]&&f.find(freq[i])!=f.end())
            {
                freq[i]--;
                ans++;
            }
            
            f.insert(freq[i]);
        }
        
        
        return ans;
    }
};