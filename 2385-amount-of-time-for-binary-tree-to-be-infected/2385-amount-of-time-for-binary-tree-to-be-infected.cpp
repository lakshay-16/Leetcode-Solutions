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
    int amountOfTime(TreeNode* root, int start) {
        vector<int> adj[100001];
        int count=0;
        int ans=0;
        
        queue<TreeNode*> pq;
        pq.push(root);
        while(!pq.empty())
        {
            TreeNode* node=pq.front();
            pq.pop();
            count++;
            
            if(node->left)
            {
                adj[node->val].push_back(node->left->val);
                adj[node->left->val].push_back(node->val);
                pq.push(node->left);
            }
            
             if(node->right)
            {
                adj[node->val].push_back(node->right->val);
                adj[node->right->val].push_back(node->val);
                pq.push(node->right);
            }
        }
        
        vector<int> vis(100001,0);
  
        queue<int> q;
        q.push(start);
        vis[start]=1;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                int node=q.front();
                q.pop();
                
                for(auto x:adj[node])
                {
                    if(!vis[x])
                    {
                        vis[x]=1;
                        q.push(x);
                    }
                }
                
            }
            
            ans++;
        }
        
        
        
        return ans-1;
    }
};