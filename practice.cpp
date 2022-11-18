#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node* prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }

    Node()
    {
        next = NULL;
        prev = NULL;
    }
};

class Operations
{
    public:
    Node* head = NULL;
    void insertathead(Node* n1);
    void display(Node* n1);
    void insertatkey(Node* n1, int key);
    void deleteatkey(int key);
    void deleteathead();
    void deleteatend();
};

void Operations::insertathead(Node* n1)
{
    if (head==NULL)
    {
        head = n1;
        n1 -> prev = NULL;
        n1 -> next = NULL;
    }

    else
    {
        n1 -> next = head;
        n1 -> prev = NULL;
        head -> prev = n1;
        head = n1;
    }
};

void Operations::display(Node* n1)
{
    n1 = head;

    while(n1!=NULL)
    {
        cout << n1->data << " ";
        n1 = n1 -> next;
    }
};

void Operations::insertatkey(Node* n1, int key)
{
    Node* ptr = head;

    while (ptr->data!=key)
    {
        ptr = ptr -> next;
    }

    n1 -> prev = ptr -> prev;
    n1 -> next = ptr;
    ptr -> prev = n1;
    n1 -> prev -> next = n1;
};

void Operations::deleteatkey(int key)
{
    Node* ptr = head;

    while (ptr->data!=key)
    {
        ptr = ptr -> next;
    }

    ptr -> prev -> next = ptr -> next;
    ptr -> next -> prev = ptr -> prev;
};

void Operations::deleteathead()
{
    head = head -> next;
    head -> next -> prev = head;
};

void Operations::deleteatend()
{
    Node* ptr = head;

    while (ptr->next!=NULL)
    {
        ptr = ptr -> next;
    }

    ptr -> prev -> next = NULL;
}

int main()
{
    int choice, x=0, v, key;

    Operations o;
    Node* n1;

    while (x!=100)
    {
        cout << "CHOICE: " << endl;
        cin >> choice;

        if (choice == 1)
        {
            cin >> v;
            n1 = new Node(v);
            o.insertathead(n1);
        }

        if (choice == 2)
        {
            n1 = new Node();
            o.display(n1);
        }

        if (choice == 3)
        {
            cin >> v;
            cin >> key;
            n1 = new Node(v);
            o.insertatkey(n1,key);
        }

        if (choice == 4)
        {
            cin >> key;
            o.deleteatkey(key);
        }

        if (choice == 5)
        {
            o.deleteathead();
        }

        if (choice == 6)
        {
            o.deleteatend();
        }

        x++;
    }
}