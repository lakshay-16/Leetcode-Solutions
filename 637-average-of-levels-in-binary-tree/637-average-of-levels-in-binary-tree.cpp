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
    void mapp(TreeNode* root,map<int,vector<int>> &m,int hdis)
    {
        if(root==NULL)
            return;
        
        m[hdis].push_back(root->val);
        
        mapp(root->left,m,hdis+1);
        mapp(root->right,m,hdis+1);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
     map<int,vector<int>> m;
        mapp(root,m,0);
        vector<double> ans;
        
        for(auto x:m)
        {
        double y=0;
            for(auto z:x.second)
                y+=z;
            
            y=y/x.second.size();
            ans.push_back(y);
        }
        
        return ans;
    }
};