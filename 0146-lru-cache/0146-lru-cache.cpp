class LRUCache {
public:
    class Node{
      public:  
        int key;
        int val;
        Node* next;
        Node* prev;
        
        Node(int key_, int val_){
            key=key_;
            val=val_;
            next=nullptr;
            prev=nullptr;
        }
    };
    
    unordered_map<int, Node*> mp;
    Node* head=new Node(0,0);
    Node* tail=new Node(0,0);  //initialized two basic structural nodes
    int size;
    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
        
    }
    
    void addNode(Node* temp){
        Node* nextNode=head->next;
        temp->next=nextNode;
        temp->prev=head;
        head->next=temp;
        nextNode->prev=temp;
    }
    
    void removeNode(Node* temp){
        Node* prevNode=temp->prev;
        Node* nextNode=temp->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
        
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* temp=mp[key];
            int value=temp->val;
            mp.erase(key);
            removeNode(temp); //remove node previous to the tail
            addNode(temp); //add it next to the head
            mp[key]=head->next;
            return value;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* temp=mp[key];
            mp.erase(key);
            removeNode(temp);
        }
        else if(mp.size()==size){
            Node* temp=tail->prev;
            mp.erase(temp->key);
            removeNode(temp);
        }
        if(mp.find(key)!=mp.end()){
            Node* temp=mp[key];
            mp.erase(key);
            removeNode(temp);
        }
        
            Node* newNode=new Node(key,value);
            addNode(newNode);
            mp[key]=head->next;
            
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */