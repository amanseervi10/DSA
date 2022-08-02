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
        top--;
        return arr[top+1];
    }
    int peek(){
        return arr[top];
    }
    int isempty(){
        if(top==-1){return 1;}
        else{return 0;}
    }
};

void solve(stack &s,stack &s1, int i){
    if(i==0){
        return;
    }
    else{
        if(s.peek()==s1.peek()){
             s.pop();s1.pop();
        }
        else{
            s1.push(s.peek());
            s.pop();
        }
        i--;
        solve(s,s1,i);
    }
}

int main(){
    stack s(100);
    int i=0;
    int n;
    cin>>n;
    while(n!=-1){
        s.push(n);
        i++;
        cin>>n;
    }
    stack s1(100);
    solve(s,s1,i);
    while(s1.isempty()!=1){
        cout<<s1.peek()<<" ";
        s1.pop();
    }
    return 0;
}