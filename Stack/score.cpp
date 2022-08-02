#include<iostream>
using namespace std;

int solve(string s, int n, int score, int &i){
    if(i>n-1){
        return score;
    }
    else if(s[i]==')'){
        return score;
    }
    else{
        if(s[i]=='(' && s[i+1]==')'){
            score++;i=i+2;
            score+=solve(s,n,0,i);
        }
        else{
            score=score+2*solve(s,n,0,++i);
            score+=solve(s,n,0,++i);
        }
        return score;
    }
}

int main(){
    string s;
    cin>>s;
    int score=0;
    int i=0;
    score=solve(s,s.length(),score,i);
    cout<<score;
    return 0;
}

