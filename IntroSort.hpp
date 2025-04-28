#include <bits/stdc++.h>
using namespace std;

template<typename T>
class IntroSort {
public:
    void startIntroSort(T tab[], unsigned int size);

private:
    using TP = T*; // Short alias inside the class if you want

    void swapValue(TP a, TP b);
    void InsertionSort(T arr[], TP begin, TP end);
    TP Partition(T arr[], int low, int high);
    TP MedianOfThree(TP a, TP b, TP c);
    void IntrosortUtil(T arr[], TP begin, TP end, int depthLimit);
    void sortIntroSort(T arr[], TP begin, TP end);
};

// Swap two pointers' values
template<typename T>
void IntroSort<T>::swapValue(TP a, TP b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

// Insertion Sort for small partitions
template<typename T>
void IntroSort<T>::InsertionSort(T arr[], TP begin, TP end) {
    int left = begin - arr;
    int right = end - arr;

    for (int i = left + 1; i <= right; i++) {
        T key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Partition function for QuickSort
template<typename T>
typename IntroSort<T>::TP IntroSort<T>::Partition(T arr[], int low, int high) {
    T pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (arr + i + 1);
}

// Median-of-three to choose good pivot
template<typename T>
typename IntroSort<T>::TP IntroSort<T>::MedianOfThree(TP a, TP b, TP c) {
    if (*a < *b && *b < *c) return b;
    if (*a < *c && *c <= *b) return c;
    if (*b <= *a && *a < *c) return a;
    if (*b < *c && *c <= *a) return c;
    if (*c <= *a && *a < *b) return a;
    return b;
}

// Core recursive function for Introsort
template<typename T>
void IntroSort<T>::IntrosortUtil(T arr[], TP begin, TP end, int depthLimit) {
    int size = end - begin;

    if (size < 16) {
        InsertionSort(arr, begin, end);
        return;
    }

    if (depthLimit == 0) {
        make_heap(begin, end + 1);
        sort_heap(begin, end + 1);
        return;
    }

    TP pivot = MedianOfThree(begin, begin + size / 2, end);
    swapValue(pivot, end);

    TP partitionPoint = Partition(arr, begin - arr, end - arr);
    IntrosortUtil(arr, begin, partitionPoint - 1, depthLimit - 1);
    IntrosortUtil(arr, partitionPoint + 1, end, depthLimit - 1);
}

// Public start function
template<typename T>
void IntroSort<T>::sortIntroSort(T arr[], TP begin, TP end) {
    int depthLimit = 2 * log(end - begin);
    IntrosortUtil(arr, begin, end, depthLimit);
}

template<typename T>
void IntroSort<T>::startIntroSort(T tab[], unsigned int size) {
    sortIntroSort(tab, tab, tab + size - 1);
}
