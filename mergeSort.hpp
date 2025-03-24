

class MergeSort {
        public: 
                void mergeSortStart(unsigned int* tab, int size);
        private:
                void scal(unsigned int* tab, int lewy, int srodek ,int prawy);
                void sortowaniePrzezScalanie(unsigned int* tab, int lewy, int prawy);
                unsigned int* pom;
};
