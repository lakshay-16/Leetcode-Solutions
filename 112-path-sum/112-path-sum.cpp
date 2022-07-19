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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL)
            return false;
        
        int currsum=targetSum-root->val;
        
        if(currsum==0&&!root->left&&!root->right)
            return true;
        
        
        if(hasPathSum(root->left,currsum)||hasPathSum(root->right,currsum))
            return true;
        
        return false;
    }
};