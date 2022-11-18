#include <iostream>
using namespace std;
class node {
public:
    char value;
    node* left;
    node* right;
    node* next = NULL;
    node(char c)
    {
        this->value = c;
        left = NULL;
        right = NULL;
    }
    node()
    {
        left = NULL;
        right = NULL;
    }
};

class Stack {
public:
    node* head = NULL;
    void push(node*);
    node* pop();
};

class tree {
public:
    void inorder(node* x)
    {
        
        if (x == NULL)
            return;
        else {
            inorder(x->left);
            cout << x->value;
            inorder(x->right);
        }
    }
    
    void preorder(node* x)
    {
        
        if (x == NULL)
            return;
        else {
             cout << x->value;
            preorder(x->left);
           
            preorder(x->right);
        }
    }
    
    void postorder(node* x)
    {
        
        if (x == NULL)
            return;
        else {
            postorder(x->left);
            
            postorder(x->right);
            cout << x->value;
        }
    }
};
 
void Stack::push(node* x)
{
    if (head == NULL) {
        head = x;
    }
    
    else {
        x->next = head;
        head = x;
    }
}

node* Stack::pop()
{
    node* p = head;
    head = head->next;
    return p;
}

int main()
{
    string s;
    cout << "Insert Postorder Expression: " << endl;
    cin >> s;
     int l = s.length();
    int operatorx=0;
    int operand=0;
    for (int i = 0; i < l; i++) {
      
        if (s[i] == '+' || s[i] == '-' || s[i] == '*'
            || s[i] == '/' || s[i] == '^') {
            operatorx++;
        }
        else {
            operand++;
        }
    }
    if(operand-operatorx!=1)
    {
        cout<<"Wrong input of Postfix Expression"<<endl;
    }
    if (s[0] == '+' || s[0] == '-' || s[0] == '*'
            || s[0] == '/' || s[0] == '^') {
           cout<<"The first character cannot be a operator in Postfix Expression"<<endl;
        }
    Stack e;
    tree a;
    node *x, *y, *z;
   
    for (int i = 0; i < l; i++) {
      
        if (s[i] == '+' || s[i] == '-' || s[i] == '*'
            || s[i] == '/' || s[i] == '^') {
            z = new node(s[i]);
            x = e.pop();
            y = e.pop();
            z->left = y;
            z->right = x;
            e.push(z);
        }
        else {
            z = new node(s[i]);
            e.push(z);
        }
    }
    cout<<s<<endl;
    cout << "\nThe Inorder Traversal of Expression Tree: ";
    a.inorder(z);
    cout << "\nThe Preorder Traversal of Expression Tree: ";
    a.preorder(z);
    cout << "\nThe Postorder Traversal of Expression Tree: ";
    a.postorder(z);
    return 0;
}