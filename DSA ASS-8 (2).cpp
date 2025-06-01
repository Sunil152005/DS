#include<iostream>
using namespace std;

void heapify(int arr[40], int n, int i)
{
    int smallest = i;
    int lc = 2*i + 1;
    int rc = 2*i + 2;

    if(lc < n && arr[lc] < arr[smallest])
        smallest = lc;

    if(rc < n && arr[rc] < arr[smallest])
        smallest = rc;

    if(smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void heapsort(int arr[40], int n)
{
    // Build min heap
    for(int i = (n / 2) - 1; i >= 0; i--)
        heapify(arr, n, i);

    cout << "Heap array: " << endl << "[";
    for(int i = 0; i < n; i++)
        cout << arr[i] << ",";
    cout << "]";

    // Heap sort (descending order)
    for(int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);      // move min element to end
        heapify(arr, i, 0);        // heapify reduced heap
    }

    cout << "\nSorted array (Descending): " << endl << "[";
    for(int i = 0; i < n; i++)
        cout << arr[i] << ",";
    cout << "]";
}

int main()
{
    int arr[90], n;
    cout << "Enter no of elements: ";
    cin >> n;

    cout << "Enter the elements: " << endl;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    heapsort(arr, n);

    return 0;
}
