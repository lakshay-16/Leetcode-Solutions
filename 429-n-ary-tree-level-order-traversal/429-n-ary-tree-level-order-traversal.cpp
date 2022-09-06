/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        if(root==NULL)
            return {};
        
        vector<vector<int>> ans;
        queue<Node*> pq;
        pq.push(root);
        
        while(!pq.empty())
        {
            int n=pq.size();
            vector<int> g;
            for(int i=0;i<n;i++)
            {
                Node* node=pq.front();
                pq.pop();
                g.push_back(node->val);
                
                
                for(int i=0;i<node->children.size();i++)
                pq.push(node->children[i]);
            }
            
            ans.push_back(g);
        }
        
        return ans;
    }
};