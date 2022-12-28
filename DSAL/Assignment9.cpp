// implement Heap sort to sort given set of values using max or min heap.
// ref : https : // www.geeksforgeeks.org/heap-sort-for-decreasing-order-using-min-heap/
// theory : https://www.geeksforgeeks.org/heap-sort/
// heap sort complexity is nlogn while heap complexity is n


#include <bits/stdc++.h>
using namespace std;

// program for creating min heap
void maxheapify(int arr[], int i, int n) {

        int largest = i;
        int left = 2*i;
        int right = 2*i+1;

        if( left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        if( right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if(largest != i) {
            swap(arr[i], arr[largest]);
            maxheapify(arr, largest, n);
        }
}

void minheapify(int arr[], int i, int n) {

        int largest = i;
        int left = 2*i;
        int right = 2*i+1;

        if( left < n && arr[left] < arr[largest]) {
            largest = left;
        }
        if( right < n && arr[right] < arr[largest]) {
            largest = right;
        }

        if(largest != i) {
            swap(arr[i], arr[largest]);
            minheapify(arr, largest, n);
        }
}

void heapSort(int arr[], int n) {

    for(int i = n/2; i >= 0; i--) {
        minheapify(arr, i, n);   
    }

    for(int i = n-1; i >= 0; i--) {

        swap(arr[i], arr[0]);
        minheapify(arr, 0, i);
    }
}

void maxHeapSort(int arr[], int n) {
    for(int i = n/2; i >= 0; i--) {
        maxheapify(arr, i, n);
    }

    for(int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        maxheapify(arr, 0, i);
    }
}
void printArray(int arr[], int n) {

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";
}

int main() {

    int n;
    cout <<"Enter the number of elements in the array : ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nPrinting the input array \n";
    printArray(arr, n);
    heapSort(arr, n);
    cout << "\nContent after using min heap method of sorting : \n";
    printArray(arr, n);


    maxHeapSort(arr, n);
    cout << "\nContents after using max heap method for sorting : \n";
    printArray(arr, n);
    return 0;
}