#include <bits/stdc++.h>
using namespace std;

template<typename T>
class IntroSort {
public:
    void startIntroSort(T tab[], unsigned int size);

private:
    void swapValue(T* a, T* b);
    void InsertionSort(T arr[], T* begin, T* end);
    T* Partition(T arr[], int low, int high);
    T* MedianOfThree(T* a, T* b, T* c);
    void IntrosortUtil(T arr[], T* begin, T* end, int depthLimit);
    void sortIntroSort(T arr[], T* begin, T* end);
        void heapify(T arr[], int n, int i);
        void heapSort(T arr[], int n);
};

template<typename T>
void IntroSort<T>::swapValue(T* a, T* b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

template<typename T>
void IntroSort<T>::InsertionSort(T arr[], T* begin, T* end) {
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

template<typename T>
T* IntroSort<T>::Partition(T arr[], int low, int high) {
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

template<typename T>
T* IntroSort<T>::MedianOfThree(T* a, T* b, T* c) {
    if (*a < *b && *b < *c) return b;
    if (*a < *c && *c <= *b) return c;
    if (*b <= *a && *a < *c) return a;
    if (*b < *c && *c <= *a) return c;
    if (*c <= *a && *a < *b) return a;
    return b;
}

template<typename T>
void IntroSort<T>::IntrosortUtil(T arr[], T* begin, T* end, int depthLimit) {
    int size = end - begin;

    if (size < 16) {
        InsertionSort(arr, begin, end);
        return;
    }

    if (depthLimit == 0) {
        heapSort(arr,size);
        return;
    }

    T* pivot = MedianOfThree(begin, begin + size / 2, end);
    swapValue(pivot, end);

    T* partitionPoint = Partition(arr, begin - arr, end - arr);
    IntrosortUtil(arr, begin, partitionPoint - 1, depthLimit - 1);
    IntrosortUtil(arr, partitionPoint + 1, end, depthLimit - 1);
}

template<typename T>
void IntroSort<T>::sortIntroSort(T arr[], T* begin, T* end) {
    int depthLimit = 2 * log(end - begin);
    IntrosortUtil(arr, begin, end, depthLimit);
}

template<typename T>
void IntroSort<T>::startIntroSort(T tab[], unsigned int size) {
    sortIntroSort(tab, tab, tab + size - 1);
}

template<typename T>
void IntroSort<T>::heapify(T arr[], int n, int i)
{
    int largest = i;     
        int l = 2 * i + 1;
    int r = 2 * i + 2; 
 
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        heapify(arr, n, largest);
    }
}
 
template<typename T>
void IntroSort<T>::heapSort(T arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
 
        heapify(arr, i, 0);
    }
}
