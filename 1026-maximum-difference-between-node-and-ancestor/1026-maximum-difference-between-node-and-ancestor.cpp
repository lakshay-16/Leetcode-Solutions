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
    
    int maxmin(TreeNode* root,int left,int right)
    {
        if(root==NULL)
            return right-left;
        
        left=min(left,root->val);
        right=max(right,root->val);
        int ldif=maxmin(root->left,left,right);
        int rdif=maxmin(root->right,left,right);
        
        return max(ldif,rdif);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        return maxmin(root,root->val,root->val);   
    }
};