#include <iostream>

using namespace std;

void minHeapify(int arr[], int n, int i)
{
    int l,r;
    int smallest = i;

    l = (2*i) + 1;
    r = (2*i) + 2;

    if (l<n && arr[l] < arr[smallest])
    {
        smallest = l;
    }

    if (r<n && arr[r] < arr[smallest])
    {
        smallest = r;
    }

    if (smallest != i)
    {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        minHeapify(arr,n,smallest);
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


void heapSort(int arr[], int n)
{
    for (int i=n/2-1; i>=0; i--)
    {
        minHeapify(arr,n,i);
    }

    cout << endl;
    cout << "The minimum heap is: " << endl;
    print(arr,n);

    cout << endl;
    cout << "Sorting: " << endl;

    for (int i=n-1; i>0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        minHeapify(arr,i,0);
        print(arr,n);
    }
}


int main()
{
    int n;
    cout << "Enter the number of elements in the array: " << endl;
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array: " << endl;

    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    heapSort(arr,n);

    cout << endl;
    cout << "The sorted array is: " << endl;
    print(arr,n);
}