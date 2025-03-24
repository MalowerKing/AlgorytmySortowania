#include "quicksort.hpp"

void QuickSort::startQuickSort(unsigned int *tab, int size) {
    quickSort(tab, 0, size - 1);
}

void QuickSort::quickSort(unsigned int *tab, int l, int r) {
    if (l < r) {
        int i = podzielTablice(tab, l, r);
        quickSort(tab, l, i - 1);
        quickSort(tab, i + 1, r);
    }
}

int QuickSort::podzielTablice(unsigned int *tab, int l, int r) {
    int indeksPodzialu = wybierzPunktPodzialu(l, r);
    int wartoscPodzialu = tab[indeksPodzialu];
    zamien(tab, indeksPodzialu, r);

    int aktualnaPozycja = l;
    for (int i = l; i < r; i++) {
        if (tab[i] < wartoscPodzialu) {
            zamien(tab, i, aktualnaPozycja);
            aktualnaPozycja++;
        }
    }
    zamien(tab, aktualnaPozycja, r);
    return aktualnaPozycja;
}

int QuickSort::wybierzPunktPodzialu(int l, int r) {
    return l + (r - l) / 2;
}

void QuickSort::zamien(unsigned int *tab, int i1, int i2) {
        int aux = tab[i1];
        tab[i1] = tab[i2];
        tab[i2] = aux;
}
