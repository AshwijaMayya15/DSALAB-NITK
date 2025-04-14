#include <iostream>
using namespace std;

// Function to merge two sorted subarrays
void combine(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // Create temporary arrays
    int left[n1], right[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[low..high]
    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    // Copy remaining elements of left[], if any
    while (i < n1)
        arr[k++] = left[i++];

    // Copy remaining elements of right[], if any
    while (j < n2)
        arr[k++] = right[j++];
}

// Function to divide the array
void partition(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        // Recursively divide left and right halves
        partition(arr, low, mid);
        partition(arr, mid + 1, high);

        // Merge the sorted halves
        combine(arr, low, mid, high);
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    partition(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
