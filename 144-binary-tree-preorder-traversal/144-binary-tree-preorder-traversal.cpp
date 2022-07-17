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
    void preorder(vector<int> &g,TreeNode* root)
    {
        if(root==NULL)
            return;
        
        g.push_back(root->val);
        preorder(g,root->left);
        preorder(g,root->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> g;
        preorder(g,root);
        
        return g;
    }
};