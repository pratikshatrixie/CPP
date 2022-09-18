#include<iostream>
using namespace std;
    
string input;
string stack;
int top=-1;
string output;

void push(char a)
{
    top++;
    stack[top]=a;
}

void pop1()
{
    output = output + stack[top];
}

void pop2()
{
    top--;
}


int main()
{   
    cout<<"Enter the input";
    cin>>input;
    int i=0;
 
    for(i=0; i<input.length();i++)
    {
        if(input[i]=='(')
        {
            cout<<"Push";
            cout<<input[i]<<endl;
            push(input[i]);
        }
       else if((input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='//'||input[i]=='^')&&top==-1)
       {
            cout<<"Push";
            cout<<input[i]<<endl;
            push(input[i]);
       }
        
        else if((input[i]!='+')&&(input[i]!='-')&&(input[i]!='*')&&(input[i]!='//')&&(input[i]!='(')&&(input[i]!=')')&&(input[i]!='^'))
            output = output + input[i];
       
        else if((input[i]=='+'||input[i]=='-')&&(stack[top]=='+'||stack[top]=='-'||stack[top]=='*'||stack[top]=='//'||stack[top]=='^'))
        {
            cout<<"Pop";
            cout<<input[i]<<endl;
            pop1();
            pop2();
            cout<<"Push";
            cout<<input[i]<<endl;
            push(input[i]);
        }

        else if((input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='//'||input[i]=='^')&&stack[top]=='(')
        {
            cout<<"Push";
            cout<<input[i]<<endl;
            push(input[i]);
        }

        else if((input[i]=='*'||input[i]=='//'||input[i]=='^')&&(stack[top]=='+'||stack[top]=='-'))
        {
            cout<<"Push";
            cout<<input[i]<<endl;
            push(input[i]);
        }

        else if((input[i]=='^')&&(stack[top]=='+'||stack[top]=='-'||stack[top]=='*'||stack[top]=='//'))
        {
            cout<<"Push";
            cout<<input[i]<<endl;
            push(input[i]);
        }

        else if((input[i]=='*'&& (stack[top]=='//'||stack[top]=='^')||(stack[top]=='*'||stack[top]=='^')&& input[i]=='//'))
        {
            cout<<"Pop";
            cout<<input[i]<<endl;
            pop1();
            pop2();
            cout<<"Push";
            cout<<input[i]<<endl;
            push(input[i]);
        }
        else if(input[i]=='^'&&stack[top]=='^')
        {
            cout<<"Pop";
            cout<<input[i]<<endl;
            pop1();
            pop2();
            cout<<"Push";
            cout<<input[i]<<endl;
            push(input[i]);
        }
        else if(input[i]==')')
        {
            while(stack[top]!='(')
            {
                cout<<"Pop";
                cout<<input[i]<<endl;
                pop1();
                pop2();
            }
            cout<<"Pop";
            cout<<input[i]<<endl;
            pop2();
        }

    }
    while(top!=-1)
    {
        cout<<"Pop";
        cout<<input[i]<<endl;
        pop1();
        pop2();
    }

    cout<<"The Reverse Polish Notation is "<<endl;
    cout<<output;
    cout<<endl;
    cout << "done" << endl;
}