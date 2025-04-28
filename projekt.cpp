#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <functional>
#include <fstream>
#include "quicksort.hpp"
#include "mergeSort.hpp"
#include "quickSort_firstElementPivot.hpp"
#include "IntroSort.hpp"
using namespace std;

//Deklaracja wszystkich testowych tabeli
long long tab_100[100];
long long tab_500[500];
long long tab_1000[1000];
long long tab_5000[5000];
long long tab_10000[10000];
long long tab_50000[50000];
long long tab_100000[100000];
long long tab_500000[500000];
long long tab_1000000[1000000];

fstream wyniki_Plik;

//Funkcja mierząca czas wykonania algorytmu 
//funcja musi mieć argumenty (int *tab, int size)
#include <chrono>
#include <functional>
#include <cstdlib> // For rand()

template<typename T>
long long measureTime(T* tab, int size, std::function<void(T* tab, int size)> fc) {
    auto begin = std::chrono::steady_clock::now();
    fc(tab, size);
    auto end = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count(); 
}

template<typename T>
void applyFunctionToAllTables(void (*f)(T*, int)) {
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

template<typename T>
void generateRandomNumberTables(T* tab, int size) {
    int range = size * 100;
    for (int i = 0; i < size; i++) {
        tab[i] = static_cast<T>(rand() % range);
    }
}

template<typename T>
void fill25Percent(T* tab, int size) {
    int range = size * 100;
    int number_of_ordered = size / 4;
    for (int i = 0; i < number_of_ordered; i++) {
        tab[i] = static_cast<T>(i);
    }
    for (int i = number_of_ordered; i < size; i++) {
        tab[i] = static_cast<T>((rand() % range) + size);
    }
}

template<typename T>
void fill50Percent(T* tab, int size) {
    int range = size * 100;
    int number_of_ordered = size / 2;
    for (int i = 0; i < number_of_ordered; i++) {
        tab[i] = static_cast<T>(i);
    }
    for (int i = number_of_ordered; i < size; i++) {
        tab[i] = static_cast<T>((rand() % range) + size);
    }
}

template<typename T>
void fill75Percent(T* tab, int size) {
    int range = size * 100;
    int number_of_ordered = size - (size / 4);
    for (int i = 0; i < number_of_ordered; i++) {
        tab[i] = static_cast<T>(i + 4000);
    }
    for (int i = number_of_ordered; i < size; i++) {
        tab[i] = static_cast<T>((rand() % range) + size);
    }
}

template<typename T>
void fill90Percent(T* tab, int size) {
    int range = size * 100;
    int number_of_ordered = size - (size / 10);
    for (int i = 0; i < number_of_ordered; i++) {
        tab[i] = static_cast<T>(i);
    }
    for (int i = number_of_ordered; i < size; i++) {
        tab[i] = static_cast<T>((rand() % range) + size);
    }
}

template<typename T>
void fill95Percent(T* tab, int size) {
    int range = size * 100;
    int number_of_ordered = size - (size / 20);
    for (int i = 0; i < number_of_ordered; i++) {
        tab[i] = static_cast<T>(i);
    }
    for (int i = number_of_ordered; i < size; i++) {
        tab[i] = static_cast<T>((rand() % range) + size);
    }
}

template<typename T>
void fill99Percent(T* tab, int size) {
    int range = size * 100;
    int number_of_ordered = size - (size / 100);
    for (int i = 0; i < number_of_ordered; i++) {
        tab[i] = static_cast<T>(i);
    }
    for (int i = number_of_ordered; i < size; i++) {
        tab[i] = static_cast<T>((rand() % range) + size);
    }
}

template<typename T>
void fill997Percent(T* tab, int size) {
    int range = size * 100;
    int number_of_ordered = size - (size / 300);
    for (int i = 0; i < number_of_ordered; i++) {
        tab[i] = static_cast<T>(i);
    }
    for (int i = number_of_ordered; i < size; i++) {
        tab[i] = static_cast<T>((rand() % range) + size);
    }
}

template<typename T>
void reverseOrder(T* tab, int size) {
    for (int i = 0; i < size; i++) {
        tab[i] = static_cast<T>(size - i);
    }
}


//Pokaż tablice
void showTable(long long *tab, int size) {
        for(int i = 0; i < size; i++){
                cout << tab[i] << " | ";
                if(i%20==0) cout << endl;
        }
}

//Bubble Sort
void bubbleSort(int *tab, int size) {
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

template<typename T>
long long* aplyFunctionToAllTablesMeasure(function<void(T*, int)> fc,const char* type) {

        long long *wyniki = new long long[9];

        wyniki[0] = measureTime<long long>(tab_100, 100, fc);
        wyniki[1] =measureTime<long long>(tab_500, 500, fc);
        wyniki[2] =measureTime<long long>(tab_1000, 1000, fc);
        wyniki[3] =measureTime<long long>(tab_5000, 5000, fc);
        wyniki[4] =measureTime<long long>(tab_10000, 10000, fc);
        wyniki[5] =measureTime<long long>(tab_50000, 50000, fc);
        wyniki[6] =measureTime<long long>(tab_100000, 100000, fc);
        wyniki[7] =measureTime<long long>(tab_500000, 500000, fc);
        wyniki[8] =measureTime<long long>(tab_1000000, 1000000, fc);

        return wyniki; 
}

void printTimeValues(long long* tab) {
        cout << "im in";
        for(int i = 0; i < 9; i++) {
                cout << tab[i] << "|";
        }
        cout << endl;
}

int main() {


        wyniki_Plik.open("QuickSort.csv", ios::app);
        //Quick Sort Machen
        QuickSort<long long> sort_QuickSort; 

        long long* wyniki;
        long long wyniki_avg[9] = {0};
        auto quickSortLambda = [&sort_QuickSort](long long* tab, int size) {
        sort_QuickSort.startQuickSort(tab, size);
        };
        wyniki_Plik << "typ,100,500,1 000,5 000,10 000,50 000,100 000,500 000,1 000 000," << endl;

        cout << "QuickSort\n" << "------------------------------------------------------------------------------------\n";

        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n random " << endl; 
        for(int i = 0; i < 100; i++){
        applyFunctionToAllTables<long long>(&generateRandomNumberTables);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(quickSortLambda, "random");

        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "random," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;
        
        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n 25% " << endl; 
        for(int i = 0; i < 100; i++){
        applyFunctionToAllTables<long long>(&fill25Percent);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(quickSortLambda, "25%");
        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "25%," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;

        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n 50% " << endl; 
        for(int i = 0; i < 100; i++){
        applyFunctionToAllTables<long long>(&fill50Percent);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(quickSortLambda, "50%");
        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "50%," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;
        
        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n 75% " << endl; 
        for(int i = 0; i < 100; i++){
        applyFunctionToAllTables<long long>(&fill75Percent);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(quickSortLambda, "75%");
        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "75%," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;
        
        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n 90% " << endl; 
        for(int i = 0; i < 100; i++){
        applyFunctionToAllTables<long long>(&fill90Percent);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(quickSortLambda, "90%");
        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "90%," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;
        
        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n 95% " << endl; 
        for(int i = 0; i < 100; i++){
        applyFunctionToAllTables<long long>(&fill95Percent);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(quickSortLambda, "95%");
        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "95%," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;
        
        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n 99% " << endl; 
        for(int i = 0; i < 100; i++){
        applyFunctionToAllTables<long long>(&fill99Percent);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(quickSortLambda, "99%");
        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "99%," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;
        
        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n 99.7% " << endl; 
        for(int i = 0; i < 100; i++){
        applyFunctionToAllTables<long long>(&fill997Percent);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(quickSortLambda, "99.7%");
        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "99.7%," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;

        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n reverse " << endl; 
        for(int i = 0; i < 100; i++){
        applyFunctionToAllTables<long long>(&reverseOrder);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(quickSortLambda, "reverse");
        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "reverse," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;

        showTable(tab_100, 100);

        wyniki_Plik.close();
        wyniki_Plik.open("MergeSort.csv", ios::app);

        wyniki_Plik << "typ,100,500,1 000,5 000,10 000,50 000,100 000,500 000,1 000 000," << endl;
        //Merge Sort

        cout << "\nMergeSort\n" << "------------------------------------------------------------------------------------\n";

        MergeSort<long long> sort_MergeSort;
        auto mergeSort = [&sort_MergeSort](long long* tab, int size) {
        sort_MergeSort.mergeSortStart(tab, size);
        };
        
        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n random " << endl; 
        for(int i = 0; i < 100; i++){
        applyFunctionToAllTables<long long>(&generateRandomNumberTables);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(mergeSort, "random");

        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "random," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;
        
        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n 25% " << endl; 
        for(int i = 0; i < 100; i++){
        applyFunctionToAllTables<long long>(&fill25Percent);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(mergeSort, "25%");
        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "25%," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;

        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n 50% " << endl; 
        for(int i = 0; i < 100; i++){
        applyFunctionToAllTables<long long>(&fill50Percent);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(mergeSort, "50%");
        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "50%," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;
        
        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n 75% " << endl; 
        for(int i = 0; i < 100; i++){
        applyFunctionToAllTables<long long>(&fill75Percent);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(mergeSort, "75%");
        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "75%," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;

        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n 90% " << endl; 
        for(int i = 0; i < 100; i++){
        applyFunctionToAllTables<long long>(&fill90Percent);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(mergeSort, "90%");
        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "90%," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;
        
        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n 95% " << endl; 
        for(int i = 0; i < 100; i++){
        applyFunctionToAllTables<long long>(&fill95Percent);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(mergeSort, "95%");
        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "95%," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;

        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n 99% " << endl; 
        for(int i = 0; i < 100; i++){
        applyFunctionToAllTables<long long>(&fill99Percent);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(mergeSort, "99%");
        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "99%," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;
        
        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n 99.7% " << endl; 
        for(int i = 0; i < 100; i++){
                applyFunctionToAllTables<long long>(&fill997Percent);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(mergeSort, "99.7%");
        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "99.7%," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;

        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n reverse " << endl; 
        for(int i = 0; i < 100; i++){
                applyFunctionToAllTables<long long>(&reverseOrder);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(mergeSort, "reverse");
        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "reverse," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;
        showTable(tab_100, 100);

        wyniki_Plik.close();
        wyniki_Plik.open("IntroSort.csv", ios::app);

        wyniki_Plik << "typ,100,500,1 000,5 000,10 000,50 000,100 000,500 000,1 000 000," << endl;
        //Merge Sort
        cout << "\nIntroSort\n" << "------------------------------------------------------------------------------------\n";

        IntroSort<long long> sort_IntroSort;
        auto IntroSort = [&sort_IntroSort](long long* tab, int size) {
                sort_IntroSort.startIntroSort(tab, size);
        };
        
        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n random " << endl; 
        for(int i = 0; i < 100; i++){
                applyFunctionToAllTables<long long>(&generateRandomNumberTables);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(IntroSort, "random");

        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "random," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;
        
        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n 25% " << endl; 
        for(int i = 0; i < 100; i++){
                applyFunctionToAllTables<long long>(&fill25Percent);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(IntroSort, "25%");
        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "25%," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;

        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n 50% " << endl; 
        for(int i = 0; i < 100; i++){
                applyFunctionToAllTables<long long>(&fill50Percent);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(IntroSort, "50%");
        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "50%," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;
        
        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n 75% " << endl; 
        for(int i = 0; i < 100; i++){
                applyFunctionToAllTables<long long>(&fill75Percent);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(IntroSort, "75%");
        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "75%," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;
        
        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n 90% " << endl; 
        for(int i = 0; i < 100; i++){
                applyFunctionToAllTables<long long>(&fill90Percent);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(IntroSort, "90%");
        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "90%," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;
        
        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n 95% " << endl; 
        for(int i = 0; i < 100; i++){
                applyFunctionToAllTables<long long>(&fill95Percent);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(IntroSort, "95%");
        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "95%," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;
        
        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n 99% " << endl; 
        for(int i = 0; i < 100; i++){
                applyFunctionToAllTables<long long>(&fill99Percent);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(IntroSort, "99%");
        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "99%," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;
        
        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n 99.7% " << endl; 
        for(int i = 0; i < 100; i++){
                applyFunctionToAllTables<long long>(&fill997Percent);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(IntroSort, "99.7%");
        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "99.7%," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;

        for(int i = 0; i < 9; i++) wyniki_avg[i] = 0;
        cout << "\n reverse " << endl; 
        for(int i = 0; i < 100; i++){
                applyFunctionToAllTables<long long>(&reverseOrder);
        wyniki = aplyFunctionToAllTablesMeasure<long long>(IntroSort, "reverse");
        for (int j = 0; j < 9; j++) {
                wyniki_avg[j] += wyniki[j];
        }
                delete[] wyniki;
                cout << i << " | " << flush;
        }

        for (int i = 0; i < 9; i++) {
                wyniki_avg[i] /= 100;
        }
        wyniki_Plik << "reverse," << wyniki_avg[0] << ","<< wyniki_avg[1] << ","<< wyniki_avg[2] << ","<< wyniki_avg[3] << ","<< wyniki_avg[4] << ","<< wyniki_avg[5] << ","<< wyniki_avg[6] << ","<< wyniki_avg[7] << "," << wyniki_avg[8] << "," << endl;
        showTable(tab_100, 100);


} 
