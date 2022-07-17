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
    int index=0;
       unordered_map<int,int> m;
    TreeNode* solve(vector<int> &inorder,vector<int> &preorder,int lb,int ub)
    {
        if(lb>ub)
            return NULL;
        
        TreeNode* root=new TreeNode(preorder[index++]);
        if(ub==lb)
            return root;
        
        int mid=m[root->val];
        
        root->left=solve(inorder,preorder,lb,mid-1);
        root->right=solve(inorder,preorder,mid+1,ub);
        
        return root;
    }
        
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
     
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        
        return solve(inorder,preorder,0,preorder.size()-1);
    }
};