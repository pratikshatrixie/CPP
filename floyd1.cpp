#include <iostream>
using namespace std;

int main()
{
    int n1;
    
    cout << "Hello";
    cout << "Enter the number of rows" << endl;
    cin >> n1;
    
    int k = 1;
    
    for(int i=1; i<=n1; i++)
    {
        for(int j=i; j>0; j--)
        {
            cout << k;
            k++;
        }
        
        cout << endl;
        
    }

    return 0;
}