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
    void mapp(unordered_map<int,int> &m,TreeNode* root)
    {
        if(root==NULL)
            return;
        
        m[root->val]++;
        mapp(m,root->left);
        mapp(m,root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
       unordered_map<int,int> m;
        mapp(m,root);
        
        for(auto x:m)
        {
            int y=k-x.first;
            if(y==x.first)
            {
                if(x.second>=2)
                    return true;
            }
            
           else if(m.find(y)!=m.end())
                return true;
        }
        
        return false;
    }
};