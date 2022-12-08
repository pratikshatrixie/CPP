#include <iostream>

using namespace std;

void maxHeapify(int arr[],int n, int i)
{
    int l,r;
    int largest = i;
    l = (2*i);
    r = (2*i) + 1;
    
    while (l<n && arr[l] > arr[largest])
    {
        largest = l;
    }
    
    while (r<n && arr[r] > arr[largest])
    {
        largest = r;
    }
    
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr,n,largest);
    }
    
}

void heapSort(int arr[], int n)
{
    int i;
    for (i=n/2-1; i>=0; i--)
    {
        maxHeapify(arr,n,i); 
    }
    
    for (i=n-1; i>0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        maxHeapify(arr,i,0);
    }
}

void print(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;
}

int main()
{
    int n, i;
    cout << "Enter the number of elements in the array: " << endl;
    cin >> n;
    
    int arr[n];
    
    cout << "Enter the elements in the array: " << endl;
    
    for (i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    heapSort(arr,n);
    
    print(arr,n);
    
}
