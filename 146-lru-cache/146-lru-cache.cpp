class LRUCache {
public:
    class node{
      public:
        int key;
        int val;
        node* prev;
        node* next;
        node(int k,int v)
        {
            key=k;
            val=v;
        }
    };
    
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    int cap;
    unordered_map<int,node*> m;
    
    LRUCache(int capacity) {
    cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addnode(node* curr)
    {
        node* temp=head->next;
        curr->next=temp;
        curr->prev=head;
        head->next=curr;
        temp->prev=curr;
    }
    
    void deletenode(node* del)
    {
        node* pre=del->prev;
        node* nex=del->next;
        pre->next=nex;
        nex->prev=pre;
    }
    
    int get(int key) {
        
        if(m.find(key)!=m.end())
        {
            node* res=m[key];
            int value=res->val;
            m.erase(key);
            deletenode(res);
            addnode(res);
            m[key]=head->next;
            return value;
        }
     
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            node* res=m[key];
            m.erase(key);
            deletenode(res);
        }
        
        if(m.size()==cap)
        {
            node* res=tail->prev;
            m.erase(res->key);
            deletenode(res);
        }
        
        addnode(new node(key,value));
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */