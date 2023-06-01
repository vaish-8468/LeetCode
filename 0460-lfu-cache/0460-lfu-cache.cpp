
//a struct can be defined within a class and a class can be defined within a class
class LFUCache {
    public:
    struct Node{
        public:
        int key;
        int val;
        int count;
        Node* next;
        Node* prev;
        Node(int key_,int val_){
            key=key_;
            val=val_;
            count=1;
            next=nullptr;
            prev=nullptr;
        }
    };

    struct LRU_list{
        public:
        
            Node* head;
            Node* tail;
            int size;
            
            LRU_list(){
            head=new Node(0,0); 
            tail=new Node(0,0);
            size=0;
            head->next=tail;
            tail->prev=head;
            }
    
            void addNode(Node* node){
                Node* nextNode=head->next;
                node->next=nextNode;
                node->prev=head;
                head->next=node;
                nextNode->prev=node;
                size++;
            }
    
            void removeNode(Node* node){
                    Node* nextNode=node->next;
                    Node* prevNode=node->prev;
                    prevNode->next=nextNode;
                    nextNode->prev=prevNode;
                    size--;
            }
        
    };

    int cap;
    int minFreq;
     map<int, Node*> mp; //to keep a record of the operated keys
     map<int,LRU_list*> freqList; //main DS used to perform LFU and LRU
   
    
    
    public:
    LFUCache(int capacity) {
        cap=capacity;
        minFreq=0;
       
        
    }
    
    void updateNode(Node* node){ //updates the position of the latest modified element
        mp.erase(node->key);
        freqList[node->count]->removeNode(node);
        if(node->count==minFreq && freqList[node->count]->size==0){
            minFreq++; //if it is the lFU element then after performing the operation t will no longer be the one,
            //minFreq is incremented by 1
        }
        
        LRU_list* newlist=new LRU_list();
        if(freqList.find(node->count+1)!=freqList.end()){ //since an operation is being done on the existing key element, so its freq will be incresed by 1
            newlist=freqList[node->count+1]; //if the list already exists for the particular freq
            //copy that list
        }
        node->count++; //incements the freq of the key element
        newlist->addNode(node);  //perform the addition of node in that copied list
        freqList[node->count]=newlist; //updates the modified list at that freq
        mp[node->key]=node;
}
     
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* temp=mp[key];
            int ans=temp->val;
            updateNode(temp);
            return ans;
        }
        return -1; //if the key element does not exists in mp
        
    }
    
    void put(int key, int value) {
        if(cap==0){
            return;
        }
        if(mp.find(key)!=mp.end()){ //if the key exists already
            Node* node=mp[key];
            node->val=value;
            updateNode(node);
            
        }
        else{
            if(mp.size()==cap){ //if the capacity is full
                LRU_list* list=freqList[minFreq];
                mp.erase(list->tail->prev->key);
                freqList[minFreq]->removeNode(list->tail->prev);
                //node having minFreq will be removed when LFU is being performed
            }
        
        
        //for increasing the capacity
        LRU_list*  list=new LRU_list();
        Node* newNode=new Node(key,value); //count=1 for new key element
        if(freqList.find(newNode->count)!=freqList.end()){  //if list already exists for that freq
            list=freqList[newNode->count];
        }
        list->addNode(newNode);
        mp[key]=newNode;
        freqList[newNode->count]=list;
        minFreq=1; //since it is being added as a new key element hence it will have minFreq=1
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */