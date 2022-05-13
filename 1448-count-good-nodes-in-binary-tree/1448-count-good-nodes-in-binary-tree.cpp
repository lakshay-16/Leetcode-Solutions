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
    int count=0;
    void dfs(TreeNode* root,int max)
    {
        if(root==NULL)
            return;
        
        int nmax=max;
        
        if(root->val>=max)
        {count++;
        nmax=root->val;
        }
         
        dfs(root->left,nmax);
        dfs(root->right,nmax);
    }
    
    int goodNodes(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
       dfs(root,INT_MIN);
        return count;
    }
};