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
    void dfs(TreeNode* root,int &count,int maxi)
    {
        if(root==NULL)
            return;
        
        if(root->val>=maxi)
            count++;
        
     
        int p=max(root->val,maxi);
        
        dfs(root->left,count,p);
        dfs(root->right,count,p);
    }
    
    int goodNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int count=0;
        
        dfs(root,count,INT_MIN);
        return count;
    }
};