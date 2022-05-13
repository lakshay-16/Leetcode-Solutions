/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    void mapp(map<int,vector<Node*>> &m,int hdis,Node* root)
    {
        if(root==NULL)
            return;
        
        m[hdis].push_back(root);
        
        mapp(m,hdis+1,root->left);
        mapp(m,hdis+1,root->right);
    }
    
    Node* connect(Node* root) {
        map<int,vector<Node*>> m;
        mapp(m,0,root);
        
        for(auto x:m)
        {
            for(int i=0;i<x.second.size()-1;i++)
                x.second[i]->next=x.second[i+1];
        }
        
        return root;
    }
};