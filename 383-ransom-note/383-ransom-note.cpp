class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int> letter(26,0);
        
        for(int i=0;i<magazine.size();i++)
        {
            int x=magazine[i]-'a';
            letter[x]++;
        }
        
        for(int i=0;i<ransomNote.length();i++)
        {
            int y=ransomNote[i]-'a';
            
            if(letter[y]==0)
                return false;
            
            letter[y]--;
        }
        
        
        return true;
    }
};