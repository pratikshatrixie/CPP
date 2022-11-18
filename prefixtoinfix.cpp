#include<iostream>
using namespace std;
    
string input;
string stack;
int top=-1;
int j=0, f;
string output;

void push(char a)
{
    top++;
    stack[top]=a;
}

void pop1(int f)
{
    if (f == 0)
    {
        output[j] = stack[top];
        j++;
    }

    else if (f == 1)
    {
        int k;
        for (k=j-1; k>=0; k--)
        {
            cout << output[k];
        }
    }
    
}

void pop2()
{
    top--;
}

void pop3(char c)
{
    output[j] = c;
    j++;
}


int main()
{   
    cout<<"Enter the infix expression" << endl;
    cin>>input;
    int i=0;
    int flag = 0;
 
    for(i=input.length()-1; i>=0;i--)
    {
        flag = 0;

        if(input[i]==')')
        {
            push(input[i]);
        }
       else if((input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='//'||input[i]=='^')&&top==-1)
        {
            push(input[i]);
        }
        
        else if((input[i]!='+')&&(input[i]!='-')&&(input[i]!='*')&&(input[i]!='//')&&(input[i]!='(')&&(input[i]!=')')&&(input[i]!='^'))
        { 
            pop3(input[i]);
        }
       
        else if((input[i]=='+'||input[i]=='-')&&(stack[top]=='*'||stack[top]=='//'||stack[top]=='^'))
        {
            pop1(flag);
            pop2();
            push(input[i]);
        }

        else if((input[i]=='*'||input[i]=='/')&&(stack[top]=='^'))
        {
            pop1(flag);
            pop2();
            push(input[i]);
        }

        else if((input[i]=='^')&&(stack[top]=='^'))
        {
            push(input[i]);
        }

         else if((input[i]=='*'||input[i]=='/')&&(stack[top]=='*')||stack[top]=='//')
        {
            push(input[i]);
        }

        else if((input[i]=='+'||input[i]=='-')&&(stack[top]=='+')||stack[top]=='-')
        {
            push(input[i]);
        }

        else if((input[i]=='*'||input[i]=='/')&&(stack[top]=='+')||stack[top]=='-')
        {
            push(input[i]);
        }

        else if((input[i]=='^')&&(stack[top]=='*')||stack[top]=='/')
        {
            push(input[i]);
        }

        else if(input[i]=='(')
        {
            while(stack[top]!=')')
            {
                pop1(flag);
                pop2();
            }

            pop2();
        }

    }

    while(top!=-1)
    {
        pop1(flag);
        pop2();
    }

    cout << endl;
    cout << "The Polish Notation is: ";
    flag = 1;
    pop1(flag);

}