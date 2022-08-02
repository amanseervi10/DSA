#include<iostream>
using namespace std;

struct stack{
    int top;
    int *arr;
    stack(int x){
        top=-1;
        arr=new int[x];
    }
    void push(int x){
        top++;
        arr[top]=x;
    }
    int pop(){
        int x=arr[top];
        top--;
        return x;
    }
    int peek(){
        return arr[top];
    }
    bool isempty(){
        if(top==-1){
            return true;
        }
        return false;
    }
};

struct node{
    int data;
    node* next;
};
typedef node* LPTR;

struct stack_linkedlist{
    int top;
    LPTR L;
    LPTR T;
    stack_linkedlist(){
        top=-1;
        L=NULL;
        T=NULL;
    }
    void push(int x){
        if(top==-1){
            L=new node;
            L->data=x;
            L->next=NULL;
            T=L;
            top++;
        }
        else{
            T->next=new node;
            T=T->next;
            T->data=x;
            T->next=NULL;
        }
    }
    int pop(){
        int x=T->data;
        LPTR K=L;
        while(K->next!=T){
            K=K->next;
        }
        K->next=NULL;
        T=K;
        return x;
    }
    int peek(){
        return T->data;
    }
    bool isempty(){
        if(top==-1){
            return true;
        }
        return false;
    }
};

void deletefront(LPTR &T){
    LPTR K=T;
    T=T->next;
    delete(K);
}


struct queue{
    LPTR H,R;
    queue(){
        H=NULL;
        R=NULL;
    }
    void enque(int x){
        if(H==NULL){
            H=new node;
            H->data=x;
            H->next=NULL;
            R=H;
        }
        else{
            R->next=new node;
            R=R->next;
            R->data=x;
            R->next=NULL;
        }
    }
    int deque(){
        if(H==NULL){
            return -1;
        }
        else{
            int x=H->data;
            if(H==R){
                H=NULL;
                R=NULL;
            }
            else{
                deletefront(H);
            }
            return x;
        }
    }
    bool isempty(){
        if (H==NULL){
            return true;
        }
        else{
            return false;
        }
    }
};

//stack using two queues
struct stack_queue{
    queue q1,q2;
    stack_queue(){
        
    }
    int push(int x){
        q2.enque(x);
        while(q1.isempty()!=1){
            q2.enque(q1.deque());
        }
        queue q=q1;
        q1=q2;
        q2=q;
    }
    int pop(){
        return q1.deque();
    }
    int peek(){
        return q1.H->data;
    }
    bool isempty(){
        if(q1.isempty()==1){
            return  true;
        }
        return false;
    }
};

int main(){
    stack_queue s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<s.pop()<<" ";
    s.pop();
    s.pop();
    cout<<s.pop()<<" ";
    s.push(50);
    cout<<s.peek()<<" ";
    return 0;
}