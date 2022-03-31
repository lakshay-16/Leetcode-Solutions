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
    int g=0;
    
    void sum(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        sum(root->right);
        g+=root->val;
        root->val=g;
        sum(root->left);
    }
 
    
    TreeNode* bstToGst(TreeNode* root) {
 
        TreeNode* temp=root;
        sum(temp);
        
        return root;
    }
};