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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        map<int,vector<int>> m;
        queue<pair<TreeNode*,int>> pq;
        vector<vector<int>> ans;
        
        if(root==NULL)
            return ans;
        
        pq.push({root,0});
        
        while(!pq.empty())
        {
            TreeNode* head=pq.front().first;
            int hdis=pq.front().second;
            pq.pop();
            
            m[hdis].push_back(head->val);
            
            if(head->left)
                pq.push({head->left,hdis+1});
            
            if(head->right)
                pq.push({head->right,hdis+1});
        }
        
        
        for(auto x:m)
        ans.push_back(x.second);
        
        return ans;
    }
};