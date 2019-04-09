#include "xpaint.h"
#include "xvet.h"
#define SUAPI(a,b,tipo)do{tipo SUAPI = a; a = b; b = SUAPI; }while(0)

void bubble_sort(int vet[], int size){
    int k = size - 1;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < k; j++){
            if(vet[j] > vet[j + 1]){
                xd_vet(vet, size, "rg", j, j + 1);
               SUAPI(vet[j], vet[j + 1], int);
               xd_vet(vet, size, "rg", j, j + 1);
            }
        }
        k--;      
    }
}

int main(){
    x_open(800, 500);
    xs_log("bubble/");
    int size = 20;
    int vet[size];
    srand(1);
    for(int i = 0; i < size; i++)
        vet[i] = rand() % 191 + 10;
    xd_vet(vet, size, "");
    bubble_sort(vet, size);
    xd_vet(vet, size, "");
    x_close();
}