#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <functional>
#include "quicksort.hpp"
#include "mergeSort.hpp"
using namespace std;

//Deklaracja wszystkich testowych tabeli
unsigned int tab_100[100];
unsigned int tab_500[500];
unsigned int tab_1000[1000];
unsigned int tab_5000[5000];
unsigned int tab_10000[10000];
unsigned int tab_50000[50000];
unsigned int tab_100000[100000];
unsigned int tab_500000[500000];
unsigned int tab_1000000[1000000];

//Funkcja mierząca czas wykonania algorytmu 
//funcja musi mieć argumenty (unsigned int *tab, int size)
void measureTime(unsigned int* tab, int size, std::function<void(unsigned int *tab, int size)> fc) {
        chrono::steady_clock::time_point begin = chrono::steady_clock::now();
        fc(tab, size);
        chrono::steady_clock::time_point end  = chrono::steady_clock::now();
        cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
        cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
}

void aplyFunctionToAllTables(void (*f)(unsigned int*, int)) {
    f(tab_100, 100);
    f(tab_500, 500);
    f(tab_1000, 1000);
    f(tab_5000, 5000);
    f(tab_10000, 10000);
    f(tab_50000, 50000);
    f(tab_100000, 100000);
    f(tab_500000, 500000);
    f(tab_1000000, 1000000);
}

//Uzupełnienie tabli losowymi liczbami
void generateRandomNumberTables(unsigned int *tab, int size) {
        for(int i =0; i < size; i++) {
                tab[i] = rand()%100000000;
        }
}

//Pokaż tablice
void showTable(unsigned int *tab, int size) {
        for(int i = 0; i < size; i++){
                cout << tab[i] << endl;
        }
}

//Bubble Sort
void bubbleSort(unsigned int *tab, int size) {
        bool sorted;

        for (int i = 0; i < size-1; i++) {
                sorted = false;
                for(int j = 0; j < size - i - 1; j++) {
                        if(tab[j] > tab[j + 1]) {
                                swap(tab[j], tab[ j +1]);
                                sorted = true;
                        }
                }

                if(!sorted) {
                        break;
                }
        }
}

void aplyFunctionToAllTablesMeasure(function<void(unsigned int*, int)> fc) {
        cout << "tab_100" << endl;
        measureTime(tab_100, 100, fc);
        cout << "tab_500" << endl;
        measureTime(tab_500, 500, fc);
        cout << "tab_1000" << endl;
        measureTime(tab_1000, 1000, fc);
        cout << "tab_5000" << endl;
        measureTime(tab_5000, 5000, fc);
        cout << "tab_10000" << endl;
        measureTime(tab_10000, 10000, fc);
        cout << "tab_50000" << endl;
        measureTime(tab_50000, 50000, fc);
        cout << "tab_100000" << endl;
        measureTime(tab_100000, 100000, fc);
        cout << "tab_500000" << endl;
        measureTime(tab_500000, 500000, fc);
        cout << "tab_1000000" << endl;
        measureTime(tab_1000000, 1000000, fc);
}

int main() {
        //Quick Sort Machen
        cout << "Quick Sort" << endl;
        aplyFunctionToAllTables(&generateRandomNumberTables);
        QuickSort sort_QuickSort; 

        auto quickSortLambda = [&sort_QuickSort](unsigned int* tab, int size) {
        sort_QuickSort.startQuickSort(tab, size);
        };
        aplyFunctionToAllTablesMeasure(quickSortLambda);

        cout << "Dla zabawy: Buble Sort" << endl;
        //Dla zabawy BubbleSort
        aplyFunctionToAllTables(&generateRandomNumberTables);
        MergeSort sort_MergeSort;

        auto mergeSort = [&sort_MergeSort](unsigned int* tab, int size) {
        sort_MergeSort.mergeSortStart(tab, size);
        };
        aplyFunctionToAllTablesMeasure(mergeSort);
        //aplyFunctionToAllTablesMeasure(&bubbleSort);
} 
