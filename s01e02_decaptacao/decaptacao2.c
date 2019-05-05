//
// Created by Imario on 23/02/19.
//

#include<stdio.h>
#include<stdbool.h>

int achar_vivo(int participantes[],int indice, int n_participantes){

    int pos = 0;

    if(participantes[indice] > 0){
        pos = (indice + 1) % n_participantes;
        while (participantes[pos] == 0) {
            pos = (pos + 1) % n_participantes;
        }
    }else if(participantes[indice] < 0){
        pos = indice - 1;
        if(pos < 0){
            pos = n_participantes - 1;
        }
        while (participantes[pos] == 0) {
            pos--;
            if(pos < 0){
                pos = n_participantes - 1;
            }
        }
    }
    return pos;

}

void imprime_vivos(int participantes[], int n_participantes, int escolhido){
    bool primeiro = true;

    printf("[");
    for(int i = 0; i < n_participantes; i++){

        if(participantes[i] != 0) {

            if (primeiro) {
                primeiro = false;
            } else {
                printf(" ");
            }
            if(i == escolhido && participantes[i] > 0){
                printf("%d>",participantes[escolhido]);
            }else if(i == escolhido && participantes[i] < 0){
                printf("<%d", participantes[escolhido]);
            }else{
                printf("%d",participantes[i]);
            }
        }
    }
    printf("]\n");
}
void p_Alternando(int vet[], int fase, int qtd){

    for(int i = 0; i < qtd; i++){
        if(fase > 0) {
            if (i % 2 == 0) {
                vet[i] = i + 1;
            } else {
                vet[i] = -(i + 1);
            }
        }else if(fase < 0){
            if (i % 2 == 0) {
                vet[i] = -(i + 1);
            } else {
                vet[i] = i + 1;
            }
        }

    }
}

int passar_d(int vet[],int esc,int qtd){
    int pos = 0;
    int num_vezes = 0;
    int interador = (esc + 1) % qtd;

    while(num_vezes != vet[esc]){
        if(vet[interador] != 0){
            pos = interador;
            num_vezes++;
        }
        interador = (interador + 1) % qtd;
    }
    return pos;
}
int passar_e(int vet[], int esc, int qtd){
    int pos = 0;
    int num_vezes = 0;
    int interador = esc - 1;

    if(interador < 0){
        interador = qtd - 1;
    }

    while(num_vezes != vet[esc]){
        if(vet[interador] != 0){
            pos = interador;
            num_vezes--;
        }
        interador--;
        if(interador < 0){
            interador = qtd - 1;
        }
    }
    return pos;
}
int main(){

   int size = 0;
   int esc = 0;
   int fase = 0;

   scanf("%d", &size);
   scanf("%d", &esc);
   scanf("%d", &fase);

   int vet[size];
    p_Alternando(vet,fase,size);

   esc = esc - 1;
   imprime_vivos(vet,size,esc);

   for(int i = 0; i < size -1; i++){

        int vai_morrer = achar_vivo(vet,esc,size);
        vet[vai_morrer] = 0;
        if(vet[esc] > 0){
            esc = passar_d(vet,esc,size);
        }else if(vet[esc] < 0){
            esc = passar_e(vet,esc,size);
        }
        imprime_vivos(vet,size,esc);

    }
}
