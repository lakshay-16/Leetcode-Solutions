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
    vector<double> averageOfLevels(TreeNode* root) {
        
        if(root==NULL)
            return {};
        
        vector<double> ans;
        queue<TreeNode*> pq;
        pq.push(root);
        
        while(!pq.empty())
        {
            double avg=0;
            int n=pq.size();
            
            for(int i=0;i<n;i++)
            {
                TreeNode* node=pq.front();
                    pq.pop();
                avg+=node->val;
                
                if(node->left)
                    pq.push(node->left);
                
                if(node->right)
                    pq.push(node->right);
            }
            
            avg=avg/n;
            ans.push_back(avg);
        }
        
        return ans;
    }
};