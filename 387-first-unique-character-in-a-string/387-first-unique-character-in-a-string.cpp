class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<int> letter(26,0);
        for(int i=0;i<s.length();i++)
        {
            int x=s[i]-'a';
            letter[x]++;
        }
        
        for(int i=0;i<s.length();i++)
        {
            int y=s[i]-'a';
            if(letter[y]==1)
                return i;
        }
        
        return -1;
    }
};