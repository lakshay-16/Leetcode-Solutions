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
    void mapp(TreeNode* root,map<int,int> &m,int hdis)
    {
        if(root==NULL)
            return;
        
        m[hdis]+=root->val;
        mapp(root->left,m,hdis+1);
        mapp(root->right,m,hdis+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        map<int,int> m;
        mapp(root,m,0);
        int n=m.size();
        
        return m[n-1];
    }
};