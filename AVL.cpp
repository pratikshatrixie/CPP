#include<iostream>
using namespace std;


typedef struct node{
    int data;
    node* left;
    node* right;
    int bf;
    int r;
    int l;
    node(int value)
    {
        data=value;
        left=NULL;
        right=NULL;
    }
}node;

node* insertAVL(node* root, int a)
{
    if(root==NULL)
    {
        root=new node(a);
        
    }

    else
    {
        if(a<root->data)
        {
                root->left=insertAVL(root->left,a);
        }

        else if(a>root->data)
        {
                root->right=insertAVL(root->right,a);
        }

    }

    return root;


}
void inorder(node* root)
{
    if(root==NULL)
    return;

    else
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);


    }

    return;

}
int main()
{
    int input;
    node* root=NULL;
    // root=insertAVL(root);
    for(int i=0;i<10;i++)
    {
    cin>>input;
    root=insertAVL(root,input);
    }
    inorder(root);
    return 0;
    
}