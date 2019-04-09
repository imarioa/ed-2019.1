#include "xpaint.h"
#include "xvet.h"
#define SUAPI(a,b,tipo)do{tipo SUAPI = a; a = b; b = SUAPI; }while(0)


void insertion_sort(int vet[], int size){
      int j = 0;
      for (int i = 1; i < size; i++) {
            j = i;
            while ((j > 0) && (vet[j - 1] > vet[j])) {
                  xd_vet(vet, size, "rg", j, j - 1);
                  SUAPI(vet[j], vet[j - 1], int);
                  xd_vet(vet, size, "rg", j, j - 1);
                  j--;
                  xd_vet(vet, size, "rg", j, j - 1);
            }
      }
}
int main(){
    x_open(800, 500);
    xs_log("insertion/");
    int size = 20;
    int vet[size];
    srand(1);
    for(int i = 0; i < size; i++)
        vet[i] = rand() % 191 + 10;
    xd_vet(vet, size, "");
    insertion_sort(vet, size);
    xd_vet(vet, size, "");
    x_close();
}