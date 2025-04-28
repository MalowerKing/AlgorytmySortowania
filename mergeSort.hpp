template<typename T>
class MergeSort {
public:
    void mergeSortStart(T* tab, int size) {
        pom = new T[size];
        iterativeMergeSort(tab, size);
        delete[] pom;
    }

private:
    void merge(T* tab, int left, int mid, int right) {
        int i = left;
        int j = mid + 1;

        for (int k = left; k <= right; k++) {
            pom[k] = tab[k];
        }

        for (int k = left; k <= right; k++) {
            if (i <= mid) {
                if (j <= right) {
                    if (pom[j] < pom[i]) {
                        tab[k] = pom[j++];
                    } else {
                        tab[k] = pom[i++];
                    }
                } else {
                    tab[k] = pom[i++];
                }
            } else {
                tab[k] = pom[j++];
            }
        }
    }

    void iterativeMergeSort(T* tab, int size) {
        for (int current_size = 1; current_size < size; current_size *= 2) {
            for (int left_start = 0; left_start < size - 1; left_start += 2 * current_size) {
                int mid = std::min(left_start + current_size - 1, size - 1);
                int right_end = std::min(left_start + 2 * current_size - 1, size - 1);

                merge(tab, left_start, mid, right_end);
            }
        }
    }

    T* pom;
};
