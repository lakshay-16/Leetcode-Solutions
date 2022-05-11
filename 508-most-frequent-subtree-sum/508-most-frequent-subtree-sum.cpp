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
    int sum(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        return root->val+sum(root->left)+sum(root->right);
    }
        
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        unordered_map<int,int> m;
        queue<TreeNode*> pq;
        pq.push(root);
        vector<int> ans;
        
        while(!pq.empty())
        {
            TreeNode* x=pq.front();
            pq.pop();
            
            int treesum=sum(x);
            m[treesum]++;
            
            if(x->left)
                pq.push(x->left);
            
            if(x->right)
                pq.push(x->right);
        }
        
        int count=INT_MIN;
        for(auto x:m)
            count=max(count,x.second);
        
        for(auto x:m)
            if(x.second==count)
                ans.push_back(x.first);
        
        return ans;
    }
};