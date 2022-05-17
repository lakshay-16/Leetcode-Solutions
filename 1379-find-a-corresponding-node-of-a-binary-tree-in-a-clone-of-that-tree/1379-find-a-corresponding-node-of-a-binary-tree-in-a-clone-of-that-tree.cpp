/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
           if(target==NULL)
            return NULL;
        
        queue<TreeNode*> pq;
        pq.push(cloned);
        
        queue<TreeNode*> pq1;
        pq1.push(original);
        
        
        while(!pq1.empty())
        {
            TreeNode* root=pq.front();
            TreeNode* root1=pq1.front();
            pq.pop();
            pq1.pop();
            
            if(root1==target)
            return root;
            
            if(root1->left)
            {pq.push(root->left);
            pq1.push(root1->left);
            }
            
            if(root1->right)
            {pq.push(root->right);
        pq1.push(root1->right);
            }
            }
        
        return NULL;
    }
};