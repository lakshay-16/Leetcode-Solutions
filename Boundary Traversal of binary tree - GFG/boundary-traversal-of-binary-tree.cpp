// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









 // } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
vector<int> l;
vector<int> r;
vector<int> leaves;

void leftl(Node* root)
{
    if(root==NULL)
    return;
    
    if(root->left)
    {l.push_back(root->data);
    leftl(root->left);
    }
    else if(root->right)
    {
        l.push_back(root->data);
        leftl(root->right);
    }
}

void rightl(Node* root)
{
    if(root==NULL)
    return;
    
    if(root->right)
    {
        r.push_back(root->data);
        rightl(root->right);
    }
    
    else if(root->left)
    {
        r.push_back(root->data);
        rightl(root->left);
    }
}


void leaf(Node* root)
{
    if(root==NULL)
    return;
    
     leaf(root->left);
    
    if(!root->left&&!root->right)
    leaves.push_back(root->data);
    
    leaf(root->right);
}

    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        ans.push_back(root->data);
        
        leftl(root->left);
        rightl(root->right);
        leaf(root->left);
        leaf(root->right);
        
        reverse(r.begin(),r.end());
        
        for(auto x:l)
        ans.push_back(x);
        
        for(auto x:leaves)
        ans.push_back(x);
        
        for(auto x:r)
        ans.push_back(x);
        
        return ans;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends