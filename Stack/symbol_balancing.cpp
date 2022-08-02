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
    string s;
    getline(cin,s);
    int k=s.size();
        int flag=0;
        stack s1(100);
        for (int i = 0; i < k; i++)
        {
            if(s[i]!='(' && s[i]!=')' && s[i]!='{' && s[i]!='}' && s[i]!='[' && s[i]!=']'){
                continue;
            }
            else{
                if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                    s1.push(s[i]);
                }
                else{
                    if((s[i]==')' && s1.peek()=='(') || (s[i]==']' && s1.peek()=='[') || (s[i]=='}' && s1.peek()=='{')){
                        s1.pop();
                    }
                    else{
                        cout<<0;
                        flag=1;
                        break;
                    }
                }
            }   
        }
        if(flag==0){
            cout<<1;
        }
    return 0;
}

