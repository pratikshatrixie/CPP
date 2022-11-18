#include<iostream>

using namespace std;

typedef struct node{
    int data;
    node* left;
    node* right;
    
    node(int input)
    {
        data=input;
        left=NULL;
        right=NULL;
    }
}node;

node* insertBST(node *root,int val)
{
    if(root==NULL)
    {
        return new node(val);
    }
    
    if (val<root->data)
    {
        root->left=insertBST(root->left,val);
    }
    else{
        root->right=insertBST(root->right,val);
    }
    
    return root;
}

node* inorderx(node* root)
{
     node* curr = root;
     while(curr && curr->left != NULL)
     {
          curr = curr->left;
     }
     return curr;
}
node* deleteBST(node*root,int key)
{
    if(key < root->data){
        root->left=deleteBST(root->left,key);
    }
    else if(key > root->data){
        root->right=deleteBST(root->right,key);
    }
    
    else{
        if(root->left==NULL){
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right ==NULL){
             node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = inorderx(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right,temp->data);
    }
    return root;
}

void inorder(node* root)
{
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    cout<<"BINARY SEARCH TREE"<<endl;
    
    node* root=NULL;
    int a,x=0,y,z;
    
    while(x<100)
    {
        cout<<"1. Insert 2. Delete 3. Inorder View \n";
        cin>>a;
        switch(a)
        {
            case 1:
           {
            cout<<"Enter Data: ";
            cin>>y;
            if(root==NULL)
            {
                root=insertBST(root,y);
            }
            else
            {
                insertBST(root,y);}
               
               break;
           }
            
            case 2:
            {
                cout<<"Enter the element to be deleted: ";
                cin>>z;
                root=deleteBST(root,z);
                break;
                
            }
            
            case 3:
            {
            inorder(root);
            cout<<endl;
            break;
            }
        }
    
   x++; }

    return 0;
}
