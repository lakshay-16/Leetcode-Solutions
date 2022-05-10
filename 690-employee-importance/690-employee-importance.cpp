/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
     void getans(unordered_map<int, pair<int , vector<int> > > & mp, int id,int &ans)
    {
        ans += mp[id].first;
        for(int i=0;i<(mp[id].second).size();i++)
        {
            getans(mp, (mp[id].second)[i],ans);
        }
    }
        
    int getImportance(vector<Employee*> emp, int id) {
      int ans=0;
        unordered_map<int, pair<int, vector<int> > > mp;
        for(int i=0;i<emp.size();i++)
        {
            mp[emp[i]->id].first= emp[i]->importance;
            mp[emp[i]->id].second= emp[i]->subordinates;
        }
        getans(mp,id,ans);
        return ans;
    }
};