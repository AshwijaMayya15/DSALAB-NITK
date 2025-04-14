#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int a[], int n, int i) {
    int min = i;        
    int left = 2 * i;  
    int right = 2 * i + 1; 

    if (left <= n && a[left] < a[min])
        min = left;
    if (right <= n && a[right] < a[min])
        min = right;

    if (min != i) {
        swap(a[i], a[min]);
        heapify(a, n, min);
    }
}

void buildMinHeap(int a[], int n) {
    for (int j = n / 2; j >= 1; j--) {
        heapify(a, n, j);
    }
}

void insert(int a[], int key, int &n) {
    n++;         
    a[n] = key;  
    buildMinHeap(a, n);  
}

void printHeap(int a[], int n) {
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void heapSort(int a[], int n) {
    buildMinHeap(a, n); 
    for (int i = n; i > 1; i--) { 
        swap(a[1], a[i]); 
        heapify(a, i - 1, 1); 
    }
}

string checkHeapType(int a[], int n) {
    bool isMinHeap = true, isMaxHeap = true;

    for (int i = 1; i <= n / 2; i++) 
    { 
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= n && a[i] > a[left]) 
            isMinHeap = false;
        if (right <= n && a[i] > a[right]) 
            isMinHeap = false;

        if (left <= n && a[i] < a[left]) 
            isMaxHeap = false;
        if (right <= n && a[i] < a[right]) 
            isMaxHeap = false;
    }

    if (isMinHeap) 
        return "Min Heap";
    if (isMaxHeap) 
        return "Max Heap";
    return "Invalid Heap";
}

int extractMin(int a[], int &n) {
    if (n == 0)
        return -1; 
    int minElement = a[1]; 
    a[1] = a[n]; 
    n--; 
    heapify(a, n, 1); 
    return minElement;
}

int findKthSmallest(int a[], int n, int k) {
    if (k > n) 
        return -1;

    int tempHeap[100]; 
    for (int i = 1; i <= n; i++) {
        tempHeap[i] = a[i];
    }

    int tempSize = n;
    int result;

    for (int i = 1; i <= k; i++) {
        result = extractMin(tempHeap, tempSize);
    }

    return result; 
}

// Driver code
int main() {
    int a[100] = {0, 10, 5, 20, 2, 8}, n = 5; 

    buildMinHeap(a, n);
    cout << "Min Heap before insertions: ";
    printHeap(a, n);

    insert(a, 3, n); insert(a, 1, n); insert(a, 15, n);
    cout << "Min Heap after insertions: ";
    printHeap(a, n);
    
    heapSort(a, n);
    cout << "Sorted Array: ";
    printHeap(a, n);
    
    int b[] = {0, 2, 5, 8, 10, 15}, c[] = {0, 20, 15, 10, 5, 2},d[] = {0, 10, 2, 20, 5, 8};
    int size = 5;
    cout << "Array 1: " << checkHeapType(b, size) << endl; 
    cout << "Array 2: " << checkHeapType(c, size) << endl;
    cout << "Array 3: " << checkHeapType(d, size) << endl;
    
    int k = 3;
    int kthSmallest = findKthSmallest(a, n, k);
    if (kthSmallest != -1)
        cout << k << "rd smallest element: " << kthSmallest << endl;
    else
        cout << "Invalid k!" << endl;
    return 0;
}