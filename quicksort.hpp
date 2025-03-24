//Header File dla klasy quicksort

class QuickSort {
        public:
                void startQuickSort(unsigned int *tab, int size);
        private:
                void quickSort(unsigned int *tab, int l, int r);
                int podzielTablice(unsigned int *tab, int l, int r);
                int wybierzPunktPodzialu(int l, int r);
                void zamien(unsigned int *tab, int l, int r);
};
