#include "xpaint.h"
#include "xvet.h"
#define SUAPI(a,b,tipo)do{tipo SUAPI = a; a = b; b = SUAPI; }while(0)

void selection_sort(int vet[], int size){
    int menor = 0;
    for(int i = 0; i < size; i++){
        menor = i;
        for(int j = i + 1; j < size; j++){
            if(vet[menor] > vet[j]){
                menor = j;
                xd_vet(vet, size, "y",menor);
            }
        }
        xd_vet(vet, size, "rg", i, menor);
        SUAPI(vet[menor], vet[i], int);
        xd_vet(vet, size, "rg", i, menor);

    }
}

int main(){
    x_open(800, 500);
    xs_log("selection/");
    int size = 20;
    int vet[size];
    srand(1);
    for(int i = 0; i < size; i++)
        vet[i] = rand() % 191 + 10;
    xd_vet(vet, size, "");
    selection_sort(vet, size);
    xd_vet(vet, size, "");
    x_close();
}