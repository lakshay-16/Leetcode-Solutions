class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int max1=values[0]+0;
        int maxscore=0;
        for(int i=1;i<values.size();i++)
        {
            int score=max1+values[i]-i;
            maxscore=max(maxscore,score);
            max1=max(max1,values[i]+i);
        }
        
        return maxscore;
    }
};