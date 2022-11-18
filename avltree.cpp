#include <iostream>

using namespace std;

class Node
{
    public:
    
    Node* left;
    Node* right;
    int data;
    int height;
};

Node* newnode(int data)
{
    Node* n = new Node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    
    return(n);
}

int height(Node* n)
{
    if (n==NULL)
    {
        return 0;
    }
    
    return n->height;
}

int maxheight(int n1, int n2)
{
    if (n1>n2)
    {
        return n1;
    }
    
    else
    {
        return n2;
    }
}

int getBal(Node* n)
{
    if (n==NULL)
    {
        return 0;
    }
    
    return height(n->left) - height(n->right);
}

Node* LLRotation(Node* n) 
{
    Node* k = n->left;
    Node* t = k->right;
    k->right = n;
    n->left = t;
    n->height = 1 + maxheight(height(n->left),
    height(n->right));
    k->height = 1 + maxheight(height(k->left), height(k->right));
    return k;
}

Node* RRRotation(Node* n) 
{
    Node* k = n->right;
    Node* t = k->left;
    k->left = n;
    n->right = t;
    n->height = 1 + maxheight(height(n->left),
    height(n->right));
    k->height = 1 + maxheight(height(k->left), height(k->right));
    return k;
}

Node* rotation(Node* n, int data)
{
    int balancefactor = getBal(n);

    if (balancefactor < -1 && data > n->right->data) 
    {
        cout << "RR rotation" << endl;
        return RRRotation(n);
    }

    if (balancefactor > 1 && data < n->left->data) 
    {
        cout << "LL rotation" << endl;
        return LLRotation(n);
    }
    
    if (balancefactor < -1 && data < n->right->data) 
    {
        cout << "RL rotation" << endl;
        n->right = LLRotation(n->right);
        return RRRotation(n);
    }

    if (balancefactor > 1 && data > n->left->data) 
    {
        cout << "LR rotation" << endl;
        n->left = RRRotation(n->left);
        return LLRotation(n);
    }

    return n;
}

Node* insert (Node* n, int data)
{
    if (n == NULL)
    {
        return newnode(data);
    }
    
    if (data < n->data)
    {
        n->left = insert(n->left,data);
    }
    
    if (data > n->data)
    {
        n->right = insert(n->right,data);
    }
    
    n->height = 1 + maxheight(height(n->left), height(n->right));
    
    n = rotation(n, data);
    return(n);
}

void preorder(Node* root)
{
    if (root==NULL)
    {
        return;
    }
    
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);

}

int main()
{
    int val, x=0, num;
    
    Node* root = NULL;
    cin >> num;
    
    while(x!=num)
    {      
        cout << "\nEnter value to be inserted: " << endl;
        cin >> val;
        root = insert(root, val);
        preorder(root);
        cout << " ";
        
        x++;
    }
}