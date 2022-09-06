/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        
        map<int,vector<int>> m;
        
        queue<pair<TreeNode*,int>> pq;
        pq.push({root,0});
            
        
            while(!pq.empty())
            {
                int x=pq.size();
                vector<pair<int,int>> g;
                
                while(x--)
                {
                    auto n=pq.front();  
                    pq.pop();
                    int hdis=n.second;
                    TreeNode* head=n.first;
                    
                    g.push_back({head->val,hdis});
                    
                    if(head->left)
                        pq.push({head->left,hdis-1});
                    
                    if(head->right)
                        pq.push({head->right,hdis+1});
                }
                 
                   sort(g.begin(),g.end(),[](pair<int,int> &a,pair<int,int> &b)
             {
                 if(a.second==b.second)
                     return a.first<b.first;
                 
                 return a.second<b.second;
             });
        
        for(int i=0;i<g.size();i++)
           m[g[i].second].push_back(g[i].first); 
                
                
                
            }
        
     
        
        
        for(auto p:m)
        ans.push_back(p.second);
        
        return ans;
    }
};