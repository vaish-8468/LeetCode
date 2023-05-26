//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};



int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        MyQueue *sq = new MyQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }
    }

// } Driver Code Ends


/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

//Function to push an element into the queue.
void MyQueue:: push(int x)
{
    QueueNode *node=new QueueNode(x);
    if(rear==NULL){ //node is added from rear side
        rear=node;
        front=node;
        return;
    }
    rear->next=node;
    rear=node;
        // Your Code
}
//2->3->4 etc
//nodes are added from rear side whereas nodes are being deleted fromthe front side

//Function to pop front element from the queue.
int MyQueue :: pop()
{
    if(front==NULL){
        return -1; //node is deleted from front side
    }
    int ans=front->data;
    QueueNode *temp=front;
    front=front->next;
    
    if(front==NULL){
        rear=NULL;
    }
    free(temp);
    return ans;
        // Your Code       
}
