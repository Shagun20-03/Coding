class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key, int _val){
            key=_key;
            val=_val;
        }
    };
    
    node* head=new node(-1, -1);
    node* tail=new node(-1, -1);
    int size;
    unordered_map<int, node*> m;
    
    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void deletenode(node* delnode){
        node* delprev=delnode->prev;
        node* delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    void addnode(node* newnode){
        node* temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    
    int get(int key_) {
        if(m.find(key_)!=m.end()){
            node* resnode=m[key_];
            int res=resnode->val;
            m.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            m[key_]=head->next;
            return res;
        }
        return -1;  //if element not present in map
    }
    
    void put(int key, int value) {
        //node already present in map
        if(m.find(key)!=m.end()){
            node *existingnode=m[key];
            m.erase(key);
            deletenode(existingnode);
        }
        //if map size is full
        if(m.size()==size){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */