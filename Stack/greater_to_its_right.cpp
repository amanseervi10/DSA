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

int main(){
    int i=0;
    int arr[20];
    int n;
    cin>>n;
    while(n!=-1){
        arr[i]=n;
        i++;
        cin>>n;
    }
    stack s(20),s1(20);
    s.push(arr[i-1]);
    s1.push(arr[i-1]);
    for(int j=i-2; j>=0; j--){
        while(s.peek()<arr[j]){
            s.pop();
        }
        if(s.isempty()==1){
            s.push(arr[j]);
            s1.push(arr[j]);
        }
    } 
    while(s1.top!=-1){
        cout<<s1.pop()<<" ";
    } 
    return 0;
}