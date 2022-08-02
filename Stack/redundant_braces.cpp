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
        return arr[top];;
    }
};

int main(){
    string s;
    cin>>s;
    int k=s.length();
    stack s1(k);
    int count=2;
    int flag=0;
    for (int i = 0; i < k; i++)
    {
        if(s[i]=='('||s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            s1.push(s[i]);
            count=2;
        }
        else if(s[i]>='a' && s[i]<='z'){
            count--;
        }
        else if(s[i]==')'){
            while(s1.peek()!='('){
                s1.pop();
                count=2;
            }
            s1.pop();
            count--;
        }
        if(count==0){
            flag=1;
            cout<<1<<endl;
            break;
        }
    }
    if(flag==0){
        cout<<0<<endl;
    }    
    return 0;
}
