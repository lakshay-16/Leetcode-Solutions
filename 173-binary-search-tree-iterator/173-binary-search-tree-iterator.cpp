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
class BSTIterator {
public:
    vector<int> g;
    int count=0;
    void inorder(TreeNode* root,vector<int> &g)
    {
        if(root==NULL)
            return;
        
        inorder(root->left,g);
        g.push_back(root->val);
        inorder(root->right,g);
    }
    
    BSTIterator(TreeNode* root) {
        inorder(root,g);
    }
    
    int next() {
        return g[count++];
    }
    
    bool hasNext() {
        return count<g.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */