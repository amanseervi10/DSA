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
    int push[6];
    for(int i=0; i<6; i++){
        cin>>push[i];
    }
    int pop[6];
    for(int i=0; i<6; i++){
        cin>>pop[i];
    }
    stack s(6);
    int j=0;
    for (int i = 0; i < 6; i++)
    {
        if(s.peek()==pop[i]){
            cout<<"X";
            s.pop();
        }
        else{
            while(push[j]!=pop[i]){
                s.push(push[j]);
                j++;
                cout<<"S";
            }
            s.push(push[j]);
            j++;
            cout<<"S";
            cout<<"X";
            s.pop();
        }
    }
    return 0;
}