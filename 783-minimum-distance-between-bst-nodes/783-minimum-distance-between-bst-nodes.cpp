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
        void inorder(TreeNode* root,vector<int> &g)
    {
        if(root==NULL)
            return;
        
        inorder(root->left,g);
        g.push_back(root->val);
        inorder(root->right,g);
    }
    
    int minDiffInBST(TreeNode* root) {
           vector<int> g;
        inorder(root,g);
        int ans=INT_MAX;
        
        for(int i=0;i<g.size()-1;i++)
        {
            int dif=g[i+1]-g[i];
            ans=min(ans,dif);
        }
            
        return ans;
    }
};