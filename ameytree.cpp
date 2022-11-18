#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
}Node;

int main()
{
    Node* root = new Node(1);
}


