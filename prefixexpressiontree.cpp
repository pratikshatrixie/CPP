#include <iostream>

using namespace std;

class Node
{
    public:
        char data;
        Node* right;
        Node* left;
        Node* next = NULL;

    Node(char val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
    
    Node()
    {
        right = NULL;
        left = NULL;
    }
};

class Stack
{
    public:
    
        Node* head = NULL;
        
        void push(Node* x)
        {
            if (head == NULL)
            {
                head = x;
            }
            
            else
            {
                x -> next = head;
                head = x;
            }
        }
        
        Node* pop()
        {
            Node* ptr = head;
            head = head -> next;
            return ptr;
        }
        
        void inorder(Node* y)
        {
            if (y == NULL)
            {
                return;
            }
            
            inorder(y -> left);
            cout << y -> data << " ";
            inorder(y -> right);
        }
};


int main()
{
    string input, stack, output;
    int top=-1;
    cout<<"Enter the infix expression" << endl;
    cin >> input;
    int i=0;
    int j=0;

 
    for(i=input.length()-1; i>=0;i--)
    {

        if(input[i]==')')
        {
            top++;
            stack[top]=input[i];
        }
       else if((input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='//'||input[i]=='^')&& top==-1)
        {
            top++;
            stack[top]=input[i];
        }
        
        else if((input[i]!='+')&&(input[i]!='-')&&(input[i]!='*')&&(input[i]!='//')&&(input[i]!='(')&&(input[i]!=')')&&(input[i]!='^'))
        { 
            output[j] = input[i];
            j++;
        }
       
        else if((input[i]=='+'||input[i]=='-')&&(stack[top]=='*'||stack[top]=='//'||stack[top]=='^'))
        {
            output[j] = stack[top];
            j++;

            top--;
            
            top++;,
            stack[top]=input[i];
        }

        else if((input[i]=='*'||input[i]=='/')&&(stack[top]=='^'))
        {
            output[j] = stack[top];
            j++;

            top--;
            
            top++;
            stack[top]=input[i];
        }

        else if((input[i]=='^')&&(stack[top]=='^'))
        {
            top++;
            stack[top]=input[i];
        }

         else if((input[i]=='*'||input[i]=='/')&&(stack[top]=='*')||stack[top]=='//')
        {
            top++;
            stack[top]=input[i];
        }

        else if((input[i]=='+'||input[i]=='-')&&(stack[top]=='+')||stack[top]=='-')
        {
            top++;
            stack[top]=input[i];
        }

        else if((input[i]=='*'||input[i]=='/')&&(stack[top]=='+')||stack[top]=='-')
        {
            top++;
            stack[top]=input[i];
        }

        else if((input[i]=='^')&&(stack[top]=='*')||stack[top]=='/')
        {
            top++;
            stack[top]=input[i];
        }

        else if(input[i]=='(')
        {
            while(stack[top]!=')')
            {
                output[j] = stack[top];
                j++;

                top--;
            }

            top--;
        }

    }

    while(top!=-1)
    {
        output[j] = stack[top];
        j++;

        top--;
    }

    cout << endl;
    cout << "The Polish Notation is: ";
  
    int k;

    for (int k=j-1; k>=0; k--)
    {
        cout << output[k];
    }

    Stack s;
    Node *l, *r, *z;
    

    for (k=0; k<j; k++)
    {
        if (output[k]=='+' || output[k]=='-' || output[k]=='*' || output[k]=='/' || output[k]=='^')
        {
            z = new Node(output[k]);
            l = s.pop();
            r = s.pop();
            z -> left = l;
            z -> right = r;
            s.push(z);
        }
        
        else
        {
            z = new Node(output[k]);
            s.push(z);
        }

    }
    
    cout << endl;
    cout << "The inorder traversal is: " << endl;
    s.inorder(z);
}
