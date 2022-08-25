class Solution {
public:  
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
         int n = s.length();
        vector<int> offsets(n+1);
        
        for (auto i : shifts) {
            int direction = i[2];
            
            offsets[i[0]] += (direction == 1)? 1: -1;
            offsets[i[1]+1] -= (direction == 1)? 1: -1;
        }
        
        int prefix = 0;
        string result = "";
        
        for (int j = 0; j < n; j ++) {
            prefix += offsets[j];
            while (prefix < 0) prefix += 26;
            
            int ch = (s[j] - 'a' + prefix) % 26;
            result += (char)('a' + ch);
        }
        
        return result;  
      
    }
};