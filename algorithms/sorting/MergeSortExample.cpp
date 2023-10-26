#include <iostream>
#include <vector>

// Function for merging two sorted segments
void merge(std::vector<int>& arr, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    // Create temp arrays
    std::vector<int> L(n1);
    std::vector<int> R(n2);

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[start + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[start..end]
    int i = 0;
    int j = 0;
    int k = start;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// start is for left index and end is right index of the sub-array of arr to be sorted
void mergeSort(std::vector<int>& arr, int start, int end) {
    if (start >= end)
        return; // Returns recursively

    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid); // Sorting first half
    mergeSort(arr, mid + 1, end); // Sorting second half
    merge(arr, start, mid, end); // Merging the sorted halves
}

int main() {
    // Our main function
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int arr_size = arr.size();

    std::cout << "Given array is \n";
    for (auto i : arr)
        std::cout << i << " ";

    mergeSort(arr, 0, arr_size - 1);

    std::cout << "\nSorted array is \n";
    for (auto i : arr)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
