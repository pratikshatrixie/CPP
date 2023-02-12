#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* head = NULL;

void inserthead(int b)
{
    Node* ptr;
    ptr = (Node *) malloc(sizeof(Node));
    ptr -> data = b;

    if (head == NULL)
    {
        head = ptr;
        ptr -> next = NULL;
        ptr -> prev = NULL;
    }

    else
    {
        ptr -> next = head;
        ptr -> prev = NULL;
        head -> prev = ptr;
        head = ptr;
    }
}

void insertend(int b)
{
    Node* ptr;
    ptr = (Node *) malloc(sizeof(Node));
    ptr -> data = b;

    Node* temp = head;

    if (head == NULL)
    {
        head = ptr;
        ptr -> next = NULL;
        ptr -> prev = NULL;
    }

    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }

    ptr -> next = NULL;
    ptr -> prev = temp;
    temp -> next = ptr;
}

void deletehead()
{
    (head -> next) -> prev = NULL;
    head = head -> next;
}

void deleteend()
{
    Node* temp = head;

    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }

    (temp -> prev) -> next = NULL;
}

void display()
{
    Node* temp;

    temp = head;

    while (temp != NULL)
    {
        cout << temp -> data << "->";
        temp = temp -> next; 
    }

    cout << endl;
}

void insertn(int b, int key)
{
    Node* ptr;
    ptr = (Node *) malloc (sizeof(Node));
    ptr -> data = b;
    
    Node* temp;
    temp = head;
    
    while (temp -> data != key && temp->next != NULL)
    {
        temp = temp -> next;
    }

    if (temp->next == NULL && temp->data!=key)
    {
        cout << "DATA NOT FOUND";
    }
    
    else if (temp == head)
    {
        inserthead(b);
    }

    else
    {
        (temp -> prev) -> next = ptr;
        ptr -> prev = temp -> prev;
        ptr -> next = temp;
        temp -> prev = ptr;
    }
    
}

void deleten(int key)
{
    Node* temp;
    temp = head;

    while (temp -> data != key && temp->next != NULL)
    {
        temp = temp -> next;
    }

    if (temp->next == NULL && temp->data!=key)
    {
        cout << "DATA NOT FOUND";
    }

    else if (temp == head)
    {
        deletehead();
    }

    else if (temp->next == NULL && temp->data==key)
    {
        deleteend();
    }

    else
    {
        (temp -> prev) -> next = temp -> next;
    }

    
}


int main()
{
    int choice,b,key;
    int x = 0;

    while (x<1000)
    {
        cout << "\n1. Insert at head \n2. Insert at end \n3. Delete at head \n4. Delete at end \n5.Display \n6. Insert at key \n7. Delete at key" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                cout << "Enter data" << endl;
                cin >> b;
                inserthead(b);
                break;
            }

            case 2:
            {
                cout << "Enter data" << endl;
                cin >> b;
                insertend(b);
                break;
            }

            case 3:
            {
                deletehead();
                break;
            }

            case 4:
            {
                deleteend();
                break;
            }

            case 5:
            {
                display();
                break;
            }

            case 6:
            {
                cout << "ENTER DATA" << endl;
                cin >> b;
                cout << "ENTER KEY" << endl;
                cin >> key;
                insertn(b,key);
                break;
            }

            case 7:
            {
                cout << "ENTER KEY" << endl;
                cin >> key;
                deleten(key);
            }

            x++;
        }
    }
}