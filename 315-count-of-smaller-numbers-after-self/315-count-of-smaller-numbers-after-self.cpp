class Solution {
public:
    class Node{
        public:
      int data;
        Node* left;
        Node* right;
        int lc;
        
        Node(int val)
        {
            data=val;
            left=NULL;
            right=NULL;
            lc=0;
        }
        
    };
    
       int insert(Node *node, int key){
     Node* r=NULL;
           Node* p;
    int c=0;

    while(node!=NULL){
        r=node;
        if( (node->data)>=key)
        {
          node->lc=(node->lc)+1;
			
			
            node=node->left;
        }
        else{
           c+= 1 + (node->lc);
		   
            node=node->right;
        }
    }
	
    p=new Node(key);
    if(p->data<=r->data)
    r->left=p;
    else
        r->right=p;
		
    return c;
}
    
    
    vector<int> countSmaller(vector<int>& nums) {
     int n = nums.size();
        vector<int> vect(n,0); 
		
        int j=1;
		
        while(j<n && nums[j-1]<=nums[j]) j++;
        if(j==n) return vect;
		
		
        j=n-2;
		
		
        while(j>-1 && nums[j]>=nums[j+1]){
            if(nums[j]>nums[j+1])
            vect[j]=n-j-1;
            if(nums[j]==nums[j+1]) vect[j]=vect[j+1];
            j--;
        }
		
        if(j==-1) return vect;
            
        struct Node *root = new Node(nums[n-1]);
		
		
        for(int i=n-2;i>-1;i--)    
            vect[i]=insert(root,nums[i]);
			
	
        return vect;
    }
};