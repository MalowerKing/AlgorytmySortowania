#include "mergeSort.hpp"

void MergeSort::mergeSortStart(unsigned int* tab, int size) {
        pom = new unsigned int[size];
       sortowaniePrzezScalanie(tab, 0, size);
        delete[] pom;
}

void MergeSort::sortowaniePrzezScalanie(unsigned int* tab, int lewy, int prawy) {
       if(prawy<=lewy) return;
        
        int srodek = (prawy+lewy)/2;

        sortowaniePrzezScalanie(tab, lewy, srodek);
        sortowaniePrzezScalanie(tab, srodek+1, prawy);
        scal(tab, lewy, srodek, prawy);
}

void MergeSort::scal(unsigned int* tab, int lewy, int srodek, int prawy) {
        int i = lewy, j = srodek + 1;

        for(int g = lewy; g<=prawy; g++){
                pom[g] = tab[g];
        }

        for(int k=lewy; k<=prawy; k++){
                if(i<=srodek){
                        if(j<= prawy){
                                if(pom[j]<pom[i]){
                                        tab[k] = pom[j++];
                                }
                                else {
                                        tab[k] = pom[i++];
                                }
                        }
                        else {
                                tab[k] = pom[i++];
                        }
                }
                else {
                        tab[k] = pom[j++];
                }
        }
}
