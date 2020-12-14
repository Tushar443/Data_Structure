#include <iostream>
#include <stack>
using namespace std;

char stack1[5];
int top = -1;

void check(){

    char str[]="(}";
    char com[2];
    string s="";
    //cout<<"Enter string and size of string  : "<<endl;
    //cin>>str[2];
    //cin>>s;

    for(int i=0;i<2;i++){
        if(str[i] == '(')
            {
                stack1[++top] = '(';
                continue;
            }
        if(str[i] == ')')
            {
               com[0]=stack1[top--];
               if(com[0]=='(' && str[i]==')')
                    cout<<"string is balanced"<<endl;
            }
             else
                    cout<<"string is not balanced"<<endl;
    }
}
int main()
{
   check();
    return 0;
}
