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
    void mapp(TreeNode* root,vector<int> &g)
    {
        if(root==NULL)
            return;
        
        g.push_back(root->val);
        mapp(root->left,g);
        mapp(root->right,g);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> g;
        mapp(root,g);
        
        return g;
    }
};