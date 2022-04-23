class Solution {
public:
map<string,string> mp;
    int num=0;
    // Encodes a URL to a shortened URL.
   
// Encodes a URL to a shortened URL.
string encode(string longurl) {
num++;
string addon=to_string(num);
string ans="http://tinyurl.com/";
ans+=(string)addon;
mp[ans]=longurl;
return ans;}
// Decodes a shortened URL to its orl
string decode (string shorturl) {
return mp[shorturl];
          }
          
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));