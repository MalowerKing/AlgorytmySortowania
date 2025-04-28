//Header File dla klasy quicksort

template<typename A>
class QuickSort {
        public:
                void startQuickSort(A *tab, int size) {
                        quickSort(tab, 0, size - 1);
                }
        private:
                void quickSort(A *tab, int l, int r) {
                        if (l < r) {
                                int i = podzielTablice(tab, l, r);
                                quickSort(tab, l, i - 1);
                                quickSort(tab, i + 1, r);
                            }
                }

                int podzielTablice(A *tab, int l, int r) {
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

                int wybierzPunktPodzialu(int l, int r) {
                        return l + (r - l) / 2;
                }

                void zamien(A *tab, int l, int r) {
                        int aux = tab[l];
                        tab[l] = tab[r];
                        tab[r] = aux;
                }
};
