#include<iostream>
using namespace std;

struct stack{
    int top;
    char *arr;
    stack(int x){
        top=-1;
        arr=new char[x];
    }
    void push(int x){
        top++;
        arr[top]=x;
    }
    char pop(){
        top--;
        return arr[top+1];
    }
    char peek(){
        return arr[top];;
    }
    int isempty(){
        if(top==-1){return 1;}
        else{return 0;}
    }
};

int main(){
    int a[5]={1,2,3,4,5};
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cin>>arr[i];
    }    
    int flag=1;
    for (int i = 0; i < 4; i++)
    {
        int m=0,n=0;
        for(int j=i+1; j<5; j++){
            if(arr[i]);
        }
    }
    if(flag==0){
        cout<<0;
    }
    else{
        cout<<1;
    }
    return 0;
}

